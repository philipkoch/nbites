#include "ImageAcquisition.h"
#include "VisionDef.h"
#include "../vision/FuzzyLogic.h"

#include <tgmath.h> 
#include <algorithm>

#define CPP_ACQUIRE 0

#define O_WIDTH 30   // Widths apply to all Max and Min values of that color
#define O_MAX_U 170 - O_WIDTH
#define O_MIN_V 140                
#define O_COEF  0.15 // Increase coefs to make y values more influential

#define G_WIDTH 30
#define G_MAX_U 152 - G_WIDTH
#define G_MAX_V 152 - G_WIDTH
#define G_COEF  -0.12

#define W_WIDTH 20
#define W_MAX_U 128 - W_WIDTH
#define W_MIN_U 128
#define W_MAX_V 128 - W_WIDTH
#define W_MIN_V 128
#define W_COEF .2

int ImageAcquisition::acquire_image(int rowCount,
									int colCount,
									int rowPitch,
									const uint8_t *yuv,
									uint8_t *out )
{
#if 0 
	_acquire_image (rowCount, colCount, rowPitch, yuv, out);
#else

	uint16_t *yOut      = (uint16_t*)out;
	uint8_t  *whiteOut  = out       + rowPitch*rowCount * 2;
	uint8_t  *orangeOut = whiteOut  + rowPitch*rowCount;
	uint8_t  *greenOut  = orangeOut + rowPitch*rowCount;

	unsigned short orangeWidth = O_WIDTH;
	unsigned short orangeWidth1 = (unsigned short)((255 << 8) / orangeWidth); // w1 = 255/w 	u16.8
	double orangeCoefV = -O_COEF;
	double orangeCoefU = O_COEF;

	unsigned short greenWidth = G_WIDTH;
	unsigned short greenWidth1 = (unsigned short)((255 << 8) / greenWidth);
	double greenCoefV = G_COEF;
	double greenCoefU = G_COEF;

	unsigned short whiteWidth = W_WIDTH;
	unsigned short whiteWidth1 = (unsigned short)((255 << 8) / whiteWidth);
	double whiteMaxCoef = W_COEF;
	double whiteMinCoef = -W_COEF;

	int y;

    man::vision::FuzzyThreshold sigmaY(65, 100);
    man::vision::FuzzyThreshold sigmaU(110, 150);
    man::vision::FuzzyThreshold sigmaV(105, 130);

	for (int i=0; i < rowCount; i ++, yuv += rowPitch*4){
		for (int j=0; j < colCount; j++, yuv += 4, yOut++, whiteOut++, orangeOut++, greenOut++){

			// Y Averaging
			*yOut = y = yuv[YOFFSET1] + yuv[rowPitch*4 + YOFFSET1] +
		    	yuv[YOFFSET2] + yuv[rowPitch*4 + YOFFSET2];
		   
		    // Variable used for color calcs
			y >>= 2;

			short unsigned u0, u = (yuv[UOFFSET] + yuv[rowPitch*4 + UOFFSET]) >> 1;
			short unsigned v0, v = (yuv[VOFFSET] + yuv[rowPitch*4 + VOFFSET]) >> 1;

            // NOTE detects yellow using three fuzzy threshold for testing purposes
            double yScore = sigmaY.weight(y);
            double uScore = 1 - sigmaU.weight(u);
            double vScore = sigmaV.weight(v);
            
            double smallestScore = uScore;
            if (yScore < uScore) {
                smallestScore = yScore;
            }
            if (vScore < smallestScore) {
                smallestScore = vScore;
            }
            
			*orangeOut = static_cast<int>(255*smallestScore);
		}
	}
#endif
	return 0;
}
