#pragma once

#include "RoboGrams.h"
#include "SExpr.h"
#include "Camera.h"
#include "Images.h"
#include "PMotion.pb.h"
#include "Vision.pb.h"
#include "FrontEnd.h"
#include "Edge.h"
#include "Hough.h"
#include "Kinematics.h"
#include "Homography.h"
#include "BallDetector.h"
#include "BallModel.pb.h"
#include "InertialState.pb.h"

namespace man {
namespace vision {

class VisionModule : public portals::Module {
public:
    VisionModule(int wd, int ht, std::string robotName = "");
    virtual ~VisionModule();

    portals::InPortal<messages::YUVImage> topIn;
    portals::InPortal<messages::YUVImage> bottomIn;
    portals::InPortal<messages::JointAngles> jointsIn;
    portals::InPortal<messages::InertialState> inertsIn;

    portals::OutPortal<messages::FieldLines> linesOut;
    portals::OutPortal<messages::VisionBall> ballOut;

    ImageFrontEnd* getFrontEnd(bool topCamera = true) const { return frontEnd[!topCamera]; }
    EdgeList* getEdges(bool topCamera = true) const { return edges[!topCamera]; }
    HoughLineList* getLines(bool topCamera = true) const { return houghLines[!topCamera]; }
    BallDetector* getBallDetector(bool topCamera = true) const { return ballDetector[!topCamera]; }
    HoughLineList* getHoughLines(bool topCamera = true) const { return houghLines[!topCamera]; }
    Kinematics* getKinematics(bool topCamera = true) const {return kinematics[!topCamera]; }
    FieldHomography* getFieldHomography(bool topCamera = true) const {return homography[!topCamera]; }
    FieldLineList* getFieldLines(bool topCamera = true) const { return fieldLines[!topCamera]; }
    GoalboxDetector* getBox(bool topCamera = true) const { return boxDetector[!topCamera]; }
    CornerDetector* getCorners(bool topCamera = true) const { return cornerDetector[!topCamera]; }

    // For use by Image nbcross func
    void setColorParams(Colors* colors, bool topCamera) { colorParams[!topCamera] = colors; }
    const std::string getStringFromTxtFile(std::string path);
    Colors* getColorsFromLisp(nblog::SExpr* colors, int camera);

    void setCalibrationParams(std::string robotName);
    void setCalibrationParams(int camera, std::string robotName);
    void setCalibrationParams(CalibrationParams* params, bool topCamera) { calibrationParams[!topCamera] = params; }

protected:
    virtual void run_();

private:
#ifdef USE_LOGGING
    void logImage(int i);
#endif
    void sendLinesOut();
    void updateVisionBall();

    Colors* colorParams[2];
    ImageFrontEnd* frontEnd[2];
    EdgeDetector* edgeDetector[2];
    EdgeList* edges[2];
    HoughLineList* houghLines[2];
    HoughSpace* hough[2];
    CalibrationParams* calibrationParams[2];
    Kinematics* kinematics[2];
    FieldHomography* homography[2];
    FieldLineList* fieldLines[2];
    GoalboxDetector* boxDetector[2];
    CornerDetector* cornerDetector[2];
    BallDetector* ballDetector[2];

    // Lisp tree with color params saved
    nblog::SExpr colors;

    // Tracking ball stuff
    bool ballOn;
    int ballOnCount;
    int ballOffCount;

    nblog::SExpr* calibrationLisp;
    size_t image_index;
};

}
}
