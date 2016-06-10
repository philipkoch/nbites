
#include "BallDetector.h"

#include <algorithm>
#include <iostream>


using std::to_string;

namespace man {
namespace vision {

BallDetector::BallDetector(FieldHomography* homography_,
                           Field* field_, bool topCamera_):
    homography(homography_),
    field(field_),
    topCamera(topCamera_)
{

}

BallDetector::~BallDetector() { }

void BallDetector::setDebugImage(DebugImage * di) {
    debugDraw =  *di;
}

/* This function takes in a spot generated by the spot filter
   system running on the y image and determines if the
   spot could reasonably be interpreted at one of the black
   hexagons on a ball. The spot filter makes certain kinds of
   predictible errors - e.g. seeing spots next to lines, goal
   posts and the like. True spots ought to be surrounded by white
   on more than one side.
*/
bool BallDetector::filterBlackSpots(Spot currentSpot)
{
    int WHITE_JUMP = 40;
    int MIN_CENTER_Y = 100;
	// Some ideas: spots on the ball should have white in at least two directions
    int buff = 0;
    int leftX = currentSpot.xLo() + width / 2 - buff;
    int rightX = currentSpot.xHi() + width / 2 + buff;
    int topY = currentSpot.yLo() + height / 2 - buff;
    int bottomY = currentSpot.yHi() + height / 2 + buff;
	int scan = currentSpot.innerDiam / 2;
    if (scan < 2) {
        scan = 2;
    }
    int midY = *(yImage.pixelAddr(currentSpot.ix() + width / 2,
                                  -currentSpot.iy() + height / 2)) / 4;
    // spots in robots are often actually bright, just surrounded by brighter
    if (midY > MIN_CENTER_Y) {
        return false;
    }
    int currentY = 0;
    int whites = 0;
	// scan out from each edge to see if there is a significant
    // jump in Y in at least two directions
	for (int i = leftX; i > leftX - scan; i--) {
        currentY = *(yImage.pixelAddr(i, -currentSpot.iy() + height / 2)) / 4;
        if (abs(currentY - midY) > WHITE_JUMP) {
			whites++;
			i = i - scan;
		}
	}
	for (int i = rightX; i < rightX + scan; i++) {
        currentY = *(yImage.pixelAddr(i, -currentSpot.iy() + height / 2)) / 4;
        if (abs(currentY - midY) > WHITE_JUMP) {
			whites++;
			i = i + scan;
		}
	}
	for (int i = topY; i > topY - scan; i--) {
        currentY = *(yImage.pixelAddr(currentSpot.ix() + width / 2, i)) / 4;
        if (abs(currentY - midY) > WHITE_JUMP) {
			whites++;
			i = i - scan;
		}
	}
	for (int i = bottomY; i < bottomY + scan; i++) {
        currentY = *(yImage.pixelAddr(currentSpot.ix() + width / 2, i)) / 4;
        if (abs(currentY - midY) > WHITE_JUMP) {
			whites++;
			i = i + scan;
		}
	}
    if (whites > 1) {
        if (debugBall) {
            debugDraw.drawPoint(currentSpot.ix() + width / 2, -currentSpot.iy() + height / 2, BLUE);
            std::cout << "Black blob " << (currentSpot.ix() + width / 2) << " " <<
                (-currentSpot.iy() + width / 2) << std::endl;
        }
		return true;
    } else {
        if (debugBall) {
            std::cout << "Filtered " << scan << " " << whites << std::endl;
            //debugDraw.drawPoint(currentSpot.x, currentSpot.y, RED);
        }
        return false;
    }
}

int BallDetector::scanX(int startX, int startY, int direction, int stop) {
    int newX = startX;
    for (int i = startX; i != stop && i >= 0 && i < width; i += direction) {
        getColor(i, startY);
        if (!(isWhite() || isBlack()) && isGreen()) {
            break;
        } else {
            newX = i;
        }
    }
    //std::cout << "Returning " << newX << std::endl;
    return newX;
}

int BallDetector::scanY(int startX, int startY, int direction, int stop) {
    int newY = startY;
    for (int i = startY; i != stop && i >= 0 && i < height; i += direction) {
        getColor(startX, i);
        if (!(isWhite() || isBlack()) && isGreen()) {
            break;
        } else {
            newY = i;
        }
    }
    return newY;
}

/* We have a potential ball on the horizon. Do some checking to
   screen out potential other stuff.
   This is a substantial area of possible improvement - more sanity
   checks are definitely needed!
*/
bool BallDetector::farSanityChecks(Blob blob)
{
    // if it is too close to the horizon - bad
    // if it is too greeen - bad
    int centerX = static_cast<int>(blob.centerX());
    int centerY = static_cast<int>(blob.centerY());
    int prinLength = static_cast<int>(blob.firstPrincipalLength());
    int prinLength2 = static_cast<int>(blob.secondPrincipalLength());
    // the black in the ball tends to make our blob footprint too small
    // try to expand it
    int leftX = centerX;
    int rightX = centerX;
    int bottomY = centerY;
    int topY = centerY;

    leftX = scanX(centerX - 1, centerY, -1, 1);
    rightX = scanX(centerX + 1, centerY, 1, width - 1);
    centerX = leftX + (rightX - leftX) / 2;
    topY = scanY(centerX, centerY - 1, -1, max(0, field->horizonAt(centerX)));
    bottomY = scanY(centerX, centerY + 1, 1, height - 1);
    centerY = topY + (bottomY - topY) / 2;
    int boxWidth = rightX - leftX;
    int boxHeight = bottomY - topY;
    leftX = scanX(centerX - 1, centerY, -1, 1);
    rightX = scanX(centerX + 1, centerY, 1, width - 1);
    centerX = leftX + (rightX - leftX) / 2;
    topY = scanY(centerX, centerY - 1, -1, max(0, field->horizonAt(centerX)));
    bottomY = scanY(centerX, centerY + 1, 1, height - 1);
    centerY = topY + (bottomY - topY) / 2;

    boxWidth = rightX - leftX;
    boxHeight = bottomY - topY;
    if (debugBall) {
        //debugDraw.drawBox(leftX, rightX, bottomY, topY, ORANGE);
        std::cout << "Box " << boxWidth << " " << boxHeight << std::endl;
        std::cout << "Ending at " << centerX << " " << centerY << std::endl;
    }
    int MINBOX = 8;
    if (boxWidth < MINBOX || boxHeight < MINBOX) {
        return false;
    }
    if (boxWidth > 2 * boxHeight || boxHeight > 2 * boxWidth) {
        return false;
    }
	if (boxWidth > 25 || boxHeight > 25) {
		return false;
	}
	int count = 0;
	for (int i = leftX; i < rightX; i++) {
		getColor(i, bottomY + 3);
		if (isGreen()) {
			count++;
		}
		if (count == 3) {
			return true;
		}
	}
    return false;
}

/* We have a white blob that is relatively near us. For whatever
   reason we didn't see any black blobs in it. Make sure that
   wasn't just because our black detector was bad. Watch out for
   field crosses though.
 */
bool BallDetector::nearSanityChecks(Blob blob)
{
    int centerX = static_cast<int>(blob.centerX());
    int centerY = static_cast<int>(blob.centerY());
    int prinLength = static_cast<int>(blob.firstPrincipalLength());
    int prinLength2 = static_cast<int>(blob.secondPrincipalLength());
    // the black in the ball tends to make our blob footprint too small
    // try to expand it
    int leftX = centerX;
    int rightX = centerX;
    int bottomY = centerY;
    int topY = centerY;

    leftX = scanX(centerX - 1, centerY, -1, 1);
    rightX = scanX(centerX + 1, centerY, 1, width - 1);
    centerX = leftX + (rightX - leftX) / 2;
    topY = scanY(centerX, centerY - 1, -1, max(0, field->horizonAt(centerX)));
    bottomY = scanY(centerX, centerY + 1, 1, height - 1);
    centerY = topY + (bottomY - topY) / 2;
    int boxWidth = rightX - leftX;
    int boxHeight = bottomY - topY;
    if (debugBall) {
        //debugDraw.drawBox(leftX, rightX, bottomY, topY, ORANGE);
        std::cout << "Near Box " << boxWidth << " " << boxHeight << std::endl;
        std::cout << "Ending at " << centerX << " " << centerY << std::endl;
    }
    int MINBOXWIDTH = 12;
	int MINBOXHEIGHT = 12;
    int MAXBOX = 50;
	bool atEdge = false;
	if (centerX < prinLength || centerX > width - prinLength) {
		MINBOXWIDTH = 8;
		atEdge = true;
	}
    if (boxWidth < MINBOXWIDTH || boxHeight < MINBOXHEIGHT ||
		boxWidth > MAXBOX || boxHeight > MAXBOX) {
        return false;
    }
    if (boxWidth > 2 * boxHeight || (boxHeight > 2 * boxWidth && !atEdge)
		|| boxHeight > 3 * boxWidth) {
        return false;
    }
	if (abs(boxWidth - boxHeight) > 15) {
		return false;
	}
	if (boxWidth > 5 * prinLength || boxHeight > 5 * prinLength) {
		return false;
	}
	// field cross check
	int count = 0;
    return true;

}

bool BallDetector::hardSanityCheck(int leftx, int rightx, int topy, int bottomy)
{
	int boxWidth = rightx - leftx;
	int boxHeight = bottomy - topy;

}

/* Our worst ball detector. Tries to find small white blobs
   off in the distance. The trouble is that such blobs might
   be other things. This will require a number of sanity checks.
*/
bool BallDetector::lookForFarAwayBalls(Blob blob)
{
    int FARAWAY_WHITE_SIZE = 15;
    float MIN_AREA = 10.0f;
    int centerX = static_cast<int>(blob.centerX());
    int centerY = static_cast<int>(blob.centerY());
    int prinLength = static_cast<int>(blob.firstPrincipalLength());
    int prinLength2 = static_cast<int>(blob.secondPrincipalLength());
    if (topCamera && centerY < height /3 &&
        prinLength < FARAWAY_WHITE_SIZE &&
        prinLength2 > prinLength / 2 && blob.area() > MIN_AREA &&
        prinLength2 >= 1 &&
        (centerY > field->horizonAt(centerX) || !topCamera)) {
		//return false;
        return farSanityChecks(blob);
    } else if (topCamera && centerY >= height / 3 &&
               centerY > field->horizonAt(centerX) &&
               prinLength > 3 && prinLength2 > 3) {
		return false;
        //return nearSanityChecks(blob);
	}
    return false;
}

/* Checks if two black blobs are close enough to be potentially
   part of the same ball.
*/

bool BallDetector::blobsAreClose(std::pair<int,int> first,
                                 std::pair<int,int> second)
{
    int BOTTOM_CAMERA_BLOB_NEARNESS = 25;
    int TOP_CAMERA_BLOB_NEARNESS = 28;
    int TOTAL_CLOSENESS = 45;
    int closeness = TOP_CAMERA_BLOB_NEARNESS;
    int xdiff = abs(first.first - second.first);
    int ydiff = abs(first.second - second.second);
    int ymax = max(first.second, second.second);
    if (!topCamera) {
        closeness = BOTTOM_CAMERA_BLOB_NEARNESS;
    } else {
        if (ymax > 200) {
            closeness = TOP_CAMERA_BLOB_NEARNESS;
        } else if (ymax > 160) {
            closeness = 24;
            TOTAL_CLOSENESS = 35;
        } else if (ymax > 120) {
            closeness = 17;
            TOTAL_CLOSENESS = 30;
        } else {
            closeness = 15;
            TOTAL_CLOSENESS = 25;
        }
    }
    if (xdiff < closeness && ydiff < closeness &&
        (xdiff + ydiff) < TOTAL_CLOSENESS &&
        (xdiff > 0 || ydiff > 0)) {
		int yMid = (first.second + second.second) / 2;
		int xMid = (first.first + second.first) / 2;
		int count = 0;
		int count2 = 0;
		for (int i = min(first.first, second.first);
			 i < max(first.first, second.first); i++) {
			getColor(i, yMid);
			if (isGreen()) {
				count++;
			}
			if (isWhite()) {
				count2++;
			}
		}
		if (count > 1 || count2 == 0) {
			return false;
		}
        return true;
    }
    return false;
}

/* Sometimes our balls are not tidy blobs (e.g. they are up against a
   post or a robot). So we need other methods of finding them. This
   is one such method. It looks at our filtered list of black blobs
   and tries to find groups of them that are near each other. If there
   are enough of them then it is strong evidence of a ball.
*/
bool BallDetector::findCorrelatedBlackSpots
(std::vector<std::pair<int,int>> & blackSpots,
 std::vector<Spot> & actualBlobs,
 double cameraHeight, bool & foundBall)
{   
    // loop through the filtered blobs and see if any are close together
    int correlations[blackSpots.size()];
    int correlatedTo[blackSpots.size()][blackSpots.size()];
    bool foundThree = false;
    // loop through filtered black blobs
    for (int i = 0; i < blackSpots.size(); i++) {
        std::pair<int,int> p = blackSpots[i];
        // initialize the correlations for this blob
        correlations[i] = 0;
        for (int k = 0; k < blackSpots.size(); k++) {
            correlatedTo[i][k] = 0;
        }
        // we're going to check against all other black blobs
        for (int j = 0; j < blackSpots.size(); j++) {
            std::pair<int,int> q = blackSpots[j];
            if (blobsAreClose(p, q)) {
                correlations[i] += 1;
                correlatedTo[i][j] = 1;
                // Four close black blobs is good evidence for a ball
                if (correlations[i] > 2) {
                    // grab this blob from our vector
                    foundThree = true;
#ifdef OFFLINE
                    std::cout << "Found correlated, punting for now" << std::endl;
#endif
                    std::vector<Spot> correlatedSpots;
                    // find our correlated blobs and merge them in
                    for (int k = 0; k < blackSpots.size(); k++) {
                        if (correlatedTo[i][k] == 1) {
                            correlatedSpots.push_back(actualBlobs[k]);
                            correlatedTo[k][i] = 0;
                            correlations[k] -= 1;
                        }
                    }
                    correlatedSpots.push_back(actualBlobs[i]);
                    double xsum = 0.0, ysum = 0.0, ballSpotX, ballSpotY;

                    for(int s = 0; s < correlatedSpots.size(); s++) {
                        xsum += correlatedSpots[s].ix();
                        ysum += correlatedSpots[s].iy();
                    }

                    ballSpotX = xsum/correlatedSpots.size();
                    ballSpotY = ysum/correlatedSpots.size();

					if (debugBall) {
						std::cout<<"Correlated Spots Size: "<<
							correlatedSpots.size() << " " << ballSpotX <<
							" " << ballSpotY << std::endl;
					}

                    Spot ballSpot;

                    ballSpot.x = ballSpotX * 2;
                    ballSpot.y = ballSpotY * 2;
					ballSpot.rawX = ballSpotX + width / 2;
					ballSpot.rawY = -1 * ballSpotY + height / 2;
					ballSpot.innerDiam = 5;
					if (debugBall) {
						debugDraw.drawPoint(ballSpotX+width/2,
											-1*ballSpotY + height/2,MAROON);
					}
                    makeBall(ballSpot, cameraHeight, 0.8, foundBall, true);
#ifdef OFFLINE
                    foundBall = true;
#else
                    return true;
#endif
                }
            }
        }
    }
    // If the best case didn't work out, look for 3 black blobs together
    for (int c = 0; c < blackSpots.size(); c++) {
        if ((correlations[c] > 1 || (correlations[c] == 1))
             && !foundThree) {
            std::vector<Spot> correlatedSpots;
            double ballSpotX, ballSpotY = 0;
            for (int k = 0; k < blackSpots.size(); k++) {
                if(correlatedTo[c][k] == 1) {
                    correlatedSpots.push_back(actualBlobs[k]);
                    correlatedTo[k][c] = 0;
                    correlations[k] -= 1;
                }
            }
            correlatedSpots.push_back(actualBlobs[c]);

			if (debugBall) {
				std::cout<<"Correlated Spots Size: "<<correlatedSpots.size()<<std::endl;
			}

            if(correlatedSpots.size() == 2) { //lets check the distance here
                Spot s1 = correlatedSpots[0];
                Spot s2 = correlatedSpots[1];

                double distance, upper, lower;
                //IDEA: account for area and distance thresholds based on the camera?
                if(topCamera) {
                    lower = 9.5;
                    upper = 17.2; //change from 14
                } else {
                    lower = 15.4; //change from 19.0
                    upper = 23.0;
                }

                distance = sqrt(pow((s2.ix() - s1.ix()),2) + pow((s2.iy() - s1.iy()),2));
				if (debugBall) {
					std::cout<<"Distance: "<<distance<<std::endl;
				}

                if(distance > lower && distance < upper) {
					if (debugBall) {
						std::cout<<"Distance is in the right range"<<std::endl;
					}

                    ballSpotX = (s1.ix()+s2.ix())/2;
                    ballSpotY = (s1.iy()+s2.iy())/2;
                    Spot ballSpot;
                    ballSpot.x = ballSpotX * 2;
                    ballSpot.y = ballSpotY * 2;
					ballSpot.rawX = ballSpotX + width / 2;
					ballSpot.rawY = -1 * ballSpotY + height / 2;
					ballSpot.innerDiam = 5;
					if (debugBall) {
						debugDraw.drawPoint(ballSpotX+width/2,
											-1*ballSpotY + height/2,BLUE);
					}
                    foundBall = true;
                    makeBall(ballSpot, cameraHeight, 0.6, foundBall, true);
#ifdef OFFLINE
                    return foundBall;
#else
                    return true;
#endif
                }
            } else if(correlatedSpots.size() == 3) {
                Spot s1 = correlatedSpots[0];
                Spot s2 = correlatedSpots[1];
                Spot s3 = correlatedSpots[2];

                double area, upper, lower;
                if(topCamera) {
                    upper = 181.1;
                    lower = 70;
                } else {
                    upper = 210;
                    lower = 55;
                }

                area = abs((s1.ix()*(s2.iy()-s3.iy()) + s2.ix()*(s3.iy()-s1.iy()) + s3.ix()*(s1.iy()-s2.iy()))/2);
                if(area > lower && area < upper) {
                    ballSpotX = (s1.ix()+s2.ix()+s3.ix())/3;
                    ballSpotY = (s2.iy()+s2.iy()+s3.iy())/3;

                    if (debugBall) {
                        std::cout<<"Area: "<<area<<std::endl;
                        debugDraw.drawPoint(ballSpotX+width/2,-1*ballSpotY + height/2,BLACK);
                    }
                    debugDraw.drawPoint(ballSpotX+width/2,-1*ballSpotY + height/2,BLACK);

                    Spot ballSpot;
                    ballSpot.x = ballSpotX * 2; // in half pixels
                    ballSpot.y = ballSpotY * 2;
    				ballSpot.rawX = ballSpotX + width / 2;
    				ballSpot.rawY = -1 * ballSpotY + height / 2;
    				ballSpot.innerDiam = 5;

                    foundBall = true;
                    makeBall(ballSpot, cameraHeight, 0.6, foundBall, true);
#ifdef OFFLINE
                    return foundBall;
#else
                    return true;
#endif
                }
            }
        }
    }
    return foundBall;
}


/* This function is called when one of our detectors has found a
   ball. For now it creates a ball from the spot used to find it.
   Also, it might set this as the "best" ball based on confidence
   ratings. Since we process balls in terms of highest confidence
   methods first, in practice (on the robot) this won't matter as
   we will stop looking as soon as we find one. But for debugging it
   is helpful to find all of the possible balls that vision could
   detect in every image.
*/
void BallDetector::makeBall(Spot spot, double cameraHeight, double conf,
                            bool foundBall, bool isBlack)
{
    double x_rel, y_rel;
    bool belowHoriz = homography->fieldCoords(spot.ix(), spot.iy(), x_rel, y_rel);
    Ball b(spot, x_rel, -1 * y_rel, cameraHeight, height,
           width, topCamera, spot.ix() + width / 2, -spot.iy() + height / 2, conf);
    _best = b;
#ifdef OFFLINE
	candidates.push_back(b);
#endif
}

void BallDetector::sanityChecks(int bx, int by, int radius)
{

}

void BallDetector::edgeSanityCheck(int bx, int by, int radius)
{
    int count = 0;
    radius = max(12, radius);
    if (by > ( 2 * height ) / 2) {
        radius = max(20, radius);
    }
    // Get edges from vision
    for (int i = 0; i < goodEdges.size(); i++) {
        int x = goodEdges[i].x() + width/2;
        int y = height/2 - goodEdges[i].y();
        int ang = goodEdges[i].angle();

        if (abs(bx - x) < radius && abs(by - y) < radius) {
            if (debugBall) {
                debugDraw.drawPoint(x, y, BLUE);
            }
            count++;
        }
    }
    if (debugBall) {
        std::cout << "Edge count: " << count << std::endl;
    }

}

/* Filter the edge list down to possible balls */
void BallDetector::makeEdgeList(EdgeList & edges)
{
    // Get edges from vision
    goodEdges.clear();
    AngleBinsIterator<Edge> abi(edges);
    for (Edge* e = *abi; e; e = *++abi){
        // If we are part of a hough line, we are not a ball edge
        if (e->memberOf()) { continue; }

        int x = e->x() + width/2;
        int y = height/2 - e->y();
        // if we're off the field we aren't a ball edge
        if (y < field->horizonAt(x)) { continue; }
        goodEdges.push_back(*e);
    }
}

bool BallDetector::filterWhiteSpot(Spot spot,
                                   std::vector<std::pair<int,int>> & blackSpots,
								   std::vector<std::pair<int,int>> & badBlack)
{
    // convert back to raw coordinates
    int leftX = spot.ix() + width / 2 - spot.innerDiam / 4;
    int rightX = spot.ix() + width / 2 + spot.innerDiam / 4;
    int topY = -spot.iy() + height / 2 - spot.innerDiam / 4;
    int bottomY = -spot.iy() + height / 2 + spot.innerDiam / 4;
    int midX = spot.ix() + width / 2;
    int midY = -spot.iy() + height / 2;

    // don't  bother if off the field
    if (topCamera && midY < field->horizonAt(midX)) {
        return false;
    }
    // when it is too small it is too dangerous
    if (spot.innerDiam / 4 < 2) {
        return false;
    }

    // count up how many black spots are inside
    int spots = 0;
    for (int j = 0; j < blackSpots.size(); j++) {
        std::pair<int,int> blackspot = blackSpots[j];
        if (blackspot.first > spot.xLo() + width / 2 &&
            blackspot.first < spot.xHi() + width / 2 &&
            blackspot.second > spot.yLo() + height / 2 &&
            blackspot.second < spot.yHi() + height / 2) {
            spots++;
        }
    }
    // for now, if there are no black spots then it is too dangerous
    if (spots < 1) {
        return false;
    }

    // count up how many bad black spots are inside
    int badspots = 0;
    for (int j = 0; j < badBlack.size(); j++) {
        std::pair<int,int> blackspot = badBlack[j];
        if (blackspot.first > spot.xLo() + width / 2 &&
            blackspot.first < spot.xHi() + width / 2 &&
            blackspot.second > spot.yLo() + height / 2 &&
            blackspot.second < spot.yHi() + height / 2) {
            badspots++;
        }
    }
    // for now, if there are several bad spots then it is too dangerous
    if (badspots > 1) {
        return false;
    }

    // make sure there is some part of the main spot that isn't white
    // if there is actual green then bail - probably a corner or something
    int nonWhite = 0;
    for (int i = leftX; i < rightX; i++) {
        for (int j = topY; j < bottomY; j++) {
            getColor(i, j);
            if (isGreen()) {
				if (debugBall) {
					std::cout << "Rejecting spot because of green" << std::endl;
				}
                return false;
            }
            if (!isWhite()) {
                nonWhite++;
            }
        }
    }
    return nonWhite > 0;
}

/* Main ball finding routine. Uses white and black spot detection to find the
   ball.
*/
bool BallDetector::findBall(ImageLiteU8 white, double cameraHeight,
                            EdgeList& edges)
{
	int WHITE_CANDIDATE = 1;
	int WHITE_REJECT = 2;
	int DARK_CANDIDATE = 3;
	int DARK_REJECT = 4;
	int WHITE_BLOB = 5;
	int WHITE_BLOB_BAD = 6;

    Ball reset;
    _best = reset;
    width = white.width();
    height = white.height();
#ifdef OFFLINE
    candidates.clear();
#endif
    bool foundBall = false;
    int BOTTOMEDGEWHITEMAX = 25;
    int BUFFER = 10;

    // Then we are going to filter out all of the blobs that obviously
    // aren't part of the ball
    std::vector<std::pair<int,int>> blackSpots;
    std::vector<std::pair<int,int>> badBlackSpots;
	std::vector<Spot> actualBlackSpots;
	std::vector<Spot> actualWhiteSpots;

	debugBlackSpots.clear();
	debugWhiteSpots.clear();

    SpotDetector spots;
    spots.darkSpot(true);
    spots.innerDiamCm(3.0f);
    if (!topCamera) {
        spots.innerDiamCm(3.0f);
    }
    spots.filterThreshold(140);
    spots.greenThreshold(60);
    spots.filterGain(0.5);
    spots.spotDetect(yImage, homography, &greenImage);
    SpotList spotter = spots.spots();
    for (auto i = spotter.begin(); i != spotter.end(); i++) {
        // convert back to raw coordinates
        int midX = (*i).ix() + width / 2;
        int midY = -(*i).iy() + height / 2;
		(*i).rawX = midX;
		(*i).rawY = midY;
        getColor(midX, midY);
        // if the middle of the spot is white or green, ignore it
        if (!(isWhite() || isGreen()) &&
            (!topCamera || midY > field->horizonAt(midX))) {
            if (filterBlackSpots((*i))) {
				blackSpots.push_back(std::make_pair(midX, midY));
				actualBlackSpots.push_back((*i));
				(*i).spotType = DARK_CANDIDATE;
			} else {
				(*i).spotType = DARK_REJECT;
				badBlackSpots.push_back(std::make_pair(midX, midY));
			}
			if (debugBall) {
				debugBlackSpots.push_back((*i));
			}
        }
    }
	// run blobber on parts of the image where spot detector won't work
	int bottomQuarter = height * 3 / 4;
	if (topCamera) {
		ImageLiteU8 bottomWhite(whiteImage, 0, bottomQuarter, whiteImage.width(),
								height - bottomQuarter);
		blobber.run(bottomWhite.pixelAddr(), bottomWhite.width(),
					bottomWhite.height(), bottomWhite.pitch());
	} else {
		bottomQuarter = 0;
		blobber.run(white.pixelAddr(), white.width(), white.height(), white.pitch());
	}
	for (auto i = blobber.blobs.begin(); i!=blobber.blobs.end(); i++) {
		int diam = (*i).firstPrincipalLength();
		if (diam < 20 && diam >= 10) {
			// convert this blob to a Spot
			int cx = (*i).centerX();
			int cy = (*i).centerY();
			Spot foo;
			foo.x = (cx - width / 2) * 2;
			foo.y = (cy + bottomQuarter - height / 2) * 2;
			foo.rawX = cx;
			foo.rawY = cy + bottomQuarter;
			foo.innerDiam = (*i).firstPrincipalLength() * 2;
			if (filterWhiteSpot(foo, blackSpots, badBlackSpots)) {
				foo.spotType = WHITE_BLOB;
				actualWhiteSpots.push_back(foo);
				makeBall(foo, cameraHeight, 0.75, foundBall, false);
#ifdef OFFLINE
				foundBall = true;
#else
				return true;
#endif
			} else {
				foo.spotType = WHITE_BLOB_BAD;
			}
			if (debugBall) {
				debugWhiteSpots.push_back(foo);
			}
		} else {
			if (debugBall) {
				std::cout << "Rejected blob " << diam << std::endl;
			}
		}
	}
    SpotDetector whitespots;
    whitespots.darkSpot(false);
    whitespots.innerDiamCm(13.0f);
    if (!topCamera) {
        whitespots.innerDiamCm(25.0f);
    }
    whitespots.filterThreshold(140);
    whitespots.greenThreshold(70);
    whitespots.filterGain(0.5);
    whitespots.spotDetect(yImage, homography, &greenImage);
    SpotList whitespotter = whitespots.spots();
    for (auto i = whitespotter.begin(); i != whitespotter.end(); i++) {
        int midX = (*i).ix() + width / 2;
        int midY = -(*i).iy() + height / 2;
		(*i).rawX = midX;
		(*i).rawY = midY;
        if (filterWhiteSpot((*i), blackSpots, badBlackSpots)) {
            actualWhiteSpots.push_back((*i));
            makeBall((*i), cameraHeight, 0.75, foundBall, false);
#ifdef OFFLINE
            foundBall = true;
#else
			return true;
#endif
			(*i).spotType = WHITE_CANDIDATE;
        } else if (!topCamera || midY > field->horizonAt(midX)) {
			(*i).spotType = WHITE_REJECT;
        }
		if (debugBall) {
			debugWhiteSpots.push_back((*i));
		}
    }
    if(blackSpots.size() != 0) {
    if (findCorrelatedBlackSpots(blackSpots, actualBlackSpots, cameraHeight,
                                 foundBall)) {
#ifdef OFFLINE
        foundBall = true;
#else
        return true;
#endif
	}
    }

    return foundBall;
}

/* This next batch of functions checks whether pixels are a certain
   color. The first, getColor just sets the pixel to be checked. The
   rest should be self explanatory given the pixel having been set.
   It should be noted that the numbers are pretty arbitrary. Hopefully
   that means our system is robust and they aren't actually important.
*/

void BallDetector::getColor(int x, int y) {
    if (x < 0 || y < 0 || x >= width || y >= height) {
        currentX = 0;
        currentY = 0;
    } else {
        currentX = x;
        currentY = y;
    }
}

bool BallDetector::isGreen() {
    if (*(greenImage.pixelAddr(currentX, currentY)) > 158) {
        return true;
    }
    return false;
}

bool BallDetector::isWhite() {
    if (*(whiteImage.pixelAddr(currentX, currentY)) > 88)// &&
        //*(yImage.pixelAddr(currentX, currentY)) < 350) {
    {
        return true;
    }
    return false;
}

bool BallDetector::isBlack() {
    if (*(blackImage.pixelAddr(currentX, currentY)) > 68) {
        return true;
    }
    return false;
}

void BallDetector::setImages(ImageLiteU8 white, ImageLiteU8 green,
                             ImageLiteU8 black,
                             ImageLiteU16 yImg) {
    whiteImage = white;
    greenImage = green;
    blackImage = black;
    yImage = yImg;
}

/* Ball functions.
 */

Ball::Ball(Spot & s, double x_, double y_, double cameraH_, int imgHeight_,
           int imgWidth_, bool top, double cx, double cy, double conf) :
    spot(s),
    radThresh(.3, .7),
    thresh(.5, .8),
    x_rel(x_),
    y_rel(y_),
    cameraH(cameraH_),
    imgHeight(imgHeight_),
    imgWidth(imgWidth_),
    topCamera(top),
	centerX(cx),
	centerY(cy),
    _confidence(conf)
{
    if (!top) {
        //radThresh = thresh;
        FuzzyThr relaxed(.3, .6);
        thresh = relaxed;
    }
    compute();
}

Ball::Ball() :
    thresh(0, 0),
    radThresh(0, 0),
    _confidence(0),
    dist(200000)
{ }

void Ball::compute()
{
    dist = hypot(x_rel, y_rel);
    radius = int(pixDiameterFromDist(dist));
    double hypotDist = hypot(dist, cameraH);
    expectedDiam = pixDiameterFromDist(hypotDist);

    if (dist > 500) {
        //_confidence = 0;
    }
}

std::string Ball::properties()
{
    std::string d("====Ball properties:====\n");
    d += "\tRelativePosition: " + to_string(x_rel) + " "+ to_string( y_rel) + "\n";
    d += "\tHomographyDistance is: " + to_string(dist) + "\n";
    //d += "\tdensity is: " + to_string(blob.area() / blob.count()) + "\n";
    //d += "\tcount is: " + to_string(blob.count()) + "\n";
    d += "\tlocated: (" + to_string(centerX) +  ", " +
        to_string(centerY) + ")\n";
    d += "\tprinceLens: " + to_string(radius) + " " +
        to_string(radius) + "\n";
    //d += "\taspectR is: " + to_string(blob.secondPrincipalLength() /
    //								  blob.firstPrincipalLength()) + "\n";
    d += "\texpect ball to be this diam: " + to_string(expectedDiam) + "\n";
    d += "\tdiamRatio: " + to_string(diameterRatio) + "\n";
    d += "\tdiam Confidence: " + to_string((diameterRatio> radThresh).f()) + "\n";
    d += "\n\tconfidence is: " + to_string(_confidence) +
        "\n====================\n";
    return d;
}

// The expected diameter of ball in image at distance d in CM
double Ball::pixDiameterFromDist(double d) const
{
    double trig = atan(BALL_RADIUS / d);
    return 2 * imgHeight * trig / VERT_FOV_RAD;
}



}
}
