#ifndef _ALLedNames_h_DEFINED
#define _ALLedNames_h_DEFINED

namespace ALNames {

static const std::string FaceLed ="Face/Led";
static const std::string EarLed ="Ears/Led";
static const std::string LFootLed ="LFoot/Led";
static const std::string RFootLed ="RFoot/Led";
static const std::string ChestLed ="ChestBoard/Led";

static const std::string Green ="/Green";
static const std::string Red ="/Red";
static const std::string Blue ="/Blue";

static const std::string Left ="/Left";
static const std::string Right ="/Right";

static const std::string PositionPostFix = "/Position/Actuator/Value";
static const std::string HardnessPostFix = "/Hardness/Actuator/Value";
static const std::string LedPostFix      = "/Actuator/Value";
static const std::string ValuePostFix    = "/Position/Sensor/Value";
static const std::string ValuePreFix     = "Device/SubDeviceList/";
static const std::string TempValuePostFix= "/Temperature/Sensor/Value";

enum LedColor{
    RED_LED = 0,
    GREEN_LED,
    BLUE_LED
};
enum LedOrientation{
    LEFT_LED = 0,
    RIGHT_LED
};

// NUM_FACE_LEDS refers to how many LEDS there are per eye
static const unsigned int NUM_FACE_LEDS  = 8;
static const unsigned int NUM_EAR_LEDS   = 10;
static const unsigned int NUM_FOOT_LEDS  = 1;
static const unsigned int NUM_CHEST_LEDS = 1;

/**
 * The following were added by Wils Dawson on 6/7/12.
 * The ears are broken up into comm and calibration halves where
 * calibration is toward the front of the robot.
 * The eyes are broken up into three parts (top broken in half
 * and bottom is the third segment).
 *   For the right eye, the bottom shows my goal or opp goal,
 *   the top right shows the right goal, the top left shows the left goal
 *   For the left eye, the bottom shows the ball,
 *   the top shows the role.
 */
static const unsigned int NUM_COMM_LEDS = 1;
static const unsigned int NUM_CALIBRATION_LEDS  = 1;
static const unsigned int NUM_BALL_LEDS = 5;
static const unsigned int NUM_GOALBOX_LEDS = NUM_FACE_LEDS - NUM_BALL_LEDS;
static const unsigned int NUM_ROLE_LEDS = NUM_FACE_LEDS;

static const unsigned int NUM_LED_COLORS = 3;
static const unsigned int NUM_LED_ORIENTATIONS = 2;
static const unsigned int NUM_ONE_EYE_LEDS = NUM_LED_COLORS * NUM_FACE_LEDS;

static const unsigned int NUM_UNIQUE_LEDS = 26;
static const unsigned int NUM_RGB_LEDS[NUM_UNIQUE_LEDS] ={
    NUM_CALIBRATION_LEDS,NUM_CALIBRATION_LEDS,NUM_CALIBRATION_LEDS,NUM_CALIBRATION_LEDS,NUM_CALIBRATION_LEDS,
    NUM_CALIBRATION_LEDS,NUM_CALIBRATION_LEDS,NUM_CALIBRATION_LEDS,NUM_CALIBRATION_LEDS,NUM_CALIBRATION_LEDS,
    NUM_COMM_LEDS,NUM_COMM_LEDS,NUM_COMM_LEDS,NUM_COMM_LEDS,NUM_COMM_LEDS,
    NUM_COMM_LEDS,NUM_COMM_LEDS,NUM_COMM_LEDS,NUM_COMM_LEDS,NUM_COMM_LEDS,
    NUM_ROLE_LEDS,                                 // Left Eye
    NUM_BALL_LEDS, NUM_GOALBOX_LEDS,               // Right Eye
    NUM_CHEST_LEDS,
    NUM_FOOT_LEDS,NUM_FOOT_LEDS};

static const unsigned int LED_START_COLOR[NUM_UNIQUE_LEDS] ={
    BLUE_LED,BLUE_LED,BLUE_LED,BLUE_LED,BLUE_LED,  // Ear fronts
    BLUE_LED,BLUE_LED,BLUE_LED,BLUE_LED,BLUE_LED,
    BLUE_LED,BLUE_LED,BLUE_LED,BLUE_LED,BLUE_LED,  // Ear backs
    BLUE_LED,BLUE_LED,BLUE_LED,BLUE_LED,BLUE_LED,
    RED_LED,                                       // Left Eye
    RED_LED, RED_LED,                              // Right Eye
    RED_LED,                                       // Chest
    RED_LED,RED_LED};                              // Feet

static const unsigned int LED_END_COLOR[NUM_UNIQUE_LEDS] ={
    NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,
    NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,
    NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,
    NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,NUM_LED_COLORS,
    NUM_LED_COLORS,                // Left Eye
    NUM_LED_COLORS, NUM_LED_COLORS, // Right Eye
    NUM_LED_COLORS,                // Chest
    NUM_LED_COLORS,NUM_LED_COLORS}; // Feet

static const std::string faceL[NUM_LED_ORIENTATIONS][NUM_LED_COLORS][NUM_FACE_LEDS] ={
/*  Face Leds Left */
    {
        /* Red*/
        {ValuePreFix + FaceLed + Red + Left + std::string("/0Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Left + std::string("/45Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Left + std::string("/90Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Left + std::string("/135Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Left + std::string("/180Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Left + std::string("/225Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Left + std::string("/270Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Left + std::string("/315Deg")+LedPostFix},
        /* Green*/
        {ValuePreFix + FaceLed + Green + Left + std::string("/0Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Left + std::string("/45Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Left + std::string("/90Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Left + std::string("/135Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Left + std::string("/180Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Left + std::string("/225Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Left + std::string("/270Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Left + std::string("/315Deg")+LedPostFix},
        /* Blue*/
        {ValuePreFix + FaceLed + Blue + Left + std::string("/0Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Left + std::string("/45Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Left + std::string("/90Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Left + std::string("/135Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Left + std::string("/180Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Left + std::string("/225Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Left + std::string("/270Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Left + std::string("/315Deg")+LedPostFix},
    },
/* Face Leds Right */
    {
        /* Red*/
        {ValuePreFix + FaceLed + Red + Right + std::string("/0Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Right + std::string("/45Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Right + std::string("/90Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Right + std::string("/135Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Right + std::string("/180Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Right + std::string("/225Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Right + std::string("/270Deg")+LedPostFix,
         ValuePreFix + FaceLed + Red + Right + std::string("/315Deg")+LedPostFix},
        /* Green*/
        {ValuePreFix + FaceLed + Green + Right + std::string("/0Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Right + std::string("/45Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Right + std::string("/90Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Right + std::string("/135Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Right + std::string("/180Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Right + std::string("/225Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Right + std::string("/270Deg")+LedPostFix,
         ValuePreFix + FaceLed + Green + Right + std::string("/315Deg")+LedPostFix},
        /* Blue*/
        {ValuePreFix + FaceLed + Blue + Right + std::string("/0Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Right + std::string("/45Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Right + std::string("/90Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Right + std::string("/135Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Right + std::string("/180Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Right + std::string("/225Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Right + std::string("/270Deg")+LedPostFix,
         ValuePreFix + FaceLed + Blue + Right + std::string("/315Deg")+LedPostFix},
    },
};

static const std::string earL[NUM_LED_ORIENTATIONS][NUM_EAR_LEDS] ={
/* Ear Led Left*/
    {ValuePreFix + EarLed + Left + std::string("/0Deg")+LedPostFix,
     ValuePreFix + EarLed + Left + std::string("/36Deg")+LedPostFix,
     ValuePreFix + EarLed + Left + std::string("/72Deg")+LedPostFix,
     ValuePreFix + EarLed + Left + std::string("/108Deg")+LedPostFix,
     ValuePreFix + EarLed + Left + std::string("/144Deg")+LedPostFix,
     ValuePreFix + EarLed + Left + std::string("/180Deg")+LedPostFix,
     ValuePreFix + EarLed + Left + std::string("/216Deg")+LedPostFix,
     ValuePreFix + EarLed + Left + std::string("/252Deg")+LedPostFix,
     ValuePreFix + EarLed + Left + std::string("/288Deg")+LedPostFix,
     ValuePreFix + EarLed + Left + std::string("/324Deg")+LedPostFix},
/* Ear Led Right*/
    {ValuePreFix + EarLed + Right + std::string("/0Deg")+LedPostFix,
     ValuePreFix + EarLed + Right + std::string("/36Deg")+LedPostFix,
     ValuePreFix + EarLed + Right + std::string("/72Deg")+LedPostFix,
     ValuePreFix + EarLed + Right + std::string("/108Deg")+LedPostFix,
     ValuePreFix + EarLed + Right + std::string("/144Deg")+LedPostFix,
     ValuePreFix + EarLed + Right + std::string("/180Deg")+LedPostFix,
     ValuePreFix + EarLed + Right + std::string("/216Deg")+LedPostFix,
     ValuePreFix + EarLed + Right + std::string("/252Deg")+LedPostFix,
     ValuePreFix + EarLed + Right + std::string("/288Deg")+LedPostFix,
     ValuePreFix + EarLed + Right + std::string("/324Deg")+LedPostFix},
};

static const std::string footL[NUM_LED_ORIENTATIONS][NUM_LED_COLORS]={
/* Foot Led Left*/
    {ValuePreFix +LFootLed + Red +LedPostFix,
     ValuePreFix +LFootLed + Green +LedPostFix,
     ValuePreFix +LFootLed + Blue +LedPostFix},
/* Foot Led Right*/
    {ValuePreFix +RFootLed + Red +LedPostFix,
     ValuePreFix +RFootLed + Green +LedPostFix,
     ValuePreFix +RFootLed + Blue +LedPostFix},
};
static const std::string chestL[NUM_LED_COLORS]={
/* Chest Led*/
    ValuePreFix +ChestLed + Red +LedPostFix,
    ValuePreFix +ChestLed + Green +LedPostFix,
    ValuePreFix +ChestLed + Blue +LedPostFix
};


/* NOTE: EYE LEDS ON NaoV4 ARE ROTATED (RIGHT ALSO BACKWARDS) FROM THE SPECS!!
   In other words, the specs aren't right so below is a "hack" until
   the hardware is actually to spec. HACK
*/
static const std::string ballL[NUM_LED_COLORS][NUM_BALL_LEDS] ={
/* Red*/
    {faceL[RIGHT_LED][RED_LED][2],
     faceL[RIGHT_LED][RED_LED][3],
     faceL[RIGHT_LED][RED_LED][4],
     faceL[RIGHT_LED][RED_LED][5],
     faceL[RIGHT_LED][RED_LED][6]},
/* Green*/
    {faceL[RIGHT_LED][GREEN_LED][2],
     faceL[RIGHT_LED][GREEN_LED][3],
     faceL[RIGHT_LED][GREEN_LED][4],
     faceL[RIGHT_LED][GREEN_LED][5],
     faceL[RIGHT_LED][GREEN_LED][6]},
/* Blue*/
    {faceL[RIGHT_LED][BLUE_LED][2],
     faceL[RIGHT_LED][BLUE_LED][3],
     faceL[RIGHT_LED][BLUE_LED][4],
     faceL[RIGHT_LED][BLUE_LED][5],
     faceL[RIGHT_LED][BLUE_LED][6]}
};

static const std::string goalBoxL[NUM_LED_COLORS][NUM_GOALBOX_LEDS] ={
/* Red*/
    {faceL[RIGHT_LED][RED_LED][0],
     faceL[RIGHT_LED][RED_LED][1],
     faceL[RIGHT_LED][RED_LED][7]},
/* Green*/
    {faceL[RIGHT_LED][GREEN_LED][0],
     faceL[RIGHT_LED][GREEN_LED][1],
     faceL[RIGHT_LED][GREEN_LED][7]},
/* Blue*/
    {faceL[RIGHT_LED][BLUE_LED][0],
     faceL[RIGHT_LED][BLUE_LED][1],
     faceL[RIGHT_LED][BLUE_LED][7]}
};

static const std::string roleL[NUM_LED_COLORS][NUM_ROLE_LEDS] ={
/* Red*/
    {faceL[LEFT_LED][RED_LED][0],
     faceL[LEFT_LED][RED_LED][1],
     faceL[LEFT_LED][RED_LED][2],
     faceL[LEFT_LED][RED_LED][3],
     faceL[LEFT_LED][RED_LED][4],
     faceL[LEFT_LED][RED_LED][5],
     faceL[LEFT_LED][RED_LED][6],
     faceL[LEFT_LED][RED_LED][7]},
/* Green*/
    {faceL[LEFT_LED][GREEN_LED][0],
     faceL[LEFT_LED][GREEN_LED][1],
     faceL[LEFT_LED][GREEN_LED][2],
     faceL[LEFT_LED][GREEN_LED][3],
     faceL[LEFT_LED][GREEN_LED][4],
     faceL[LEFT_LED][GREEN_LED][5],
     faceL[LEFT_LED][GREEN_LED][6],
     faceL[LEFT_LED][GREEN_LED][7]},
/* Blue*/
    {faceL[LEFT_LED][BLUE_LED][0],
     faceL[LEFT_LED][BLUE_LED][1],
     faceL[LEFT_LED][BLUE_LED][2],
     faceL[LEFT_LED][BLUE_LED][3],
     faceL[LEFT_LED][BLUE_LED][4],
     faceL[LEFT_LED][BLUE_LED][5],
     faceL[LEFT_LED][BLUE_LED][6],
     faceL[LEFT_LED][BLUE_LED][7]},
};


static const std::string strPtr = footL[RIGHT_LED][0];
static const std::string * RGB_LED_STRINGS[NUM_UNIQUE_LEDS] ={
    &earL[LEFT_LED][0],             // Left Calibration 1
    &earL[LEFT_LED][1],             // 2
    &earL[LEFT_LED][2],             // 3
    &earL[LEFT_LED][3],             // 4
    &earL[LEFT_LED][4],             // 5
    &earL[RIGHT_LED][1],            // Right Calibration 1
    &earL[RIGHT_LED][2],            // 2
    &earL[RIGHT_LED][3],            // 3
    &earL[RIGHT_LED][4],            // 4
    &earL[RIGHT_LED][5],            // 5
    &earL[LEFT_LED][5],             // Left Comm 1
    &earL[LEFT_LED][6],             // 2
    &earL[LEFT_LED][7],             // 3
    &earL[LEFT_LED][8],             // 4
    &earL[LEFT_LED][9],             // 5
    &earL[RIGHT_LED][6],            // Right Comm 1
    &earL[RIGHT_LED][7],            // 2
    &earL[RIGHT_LED][8],            // 3
    &earL[RIGHT_LED][9],            // 4
    &earL[RIGHT_LED][0],            // 5
    &roleL[0][0],                   // Role
    &ballL[0][0],                   // Ball
    &goalBoxL[0][0],                // Goalbox
    &chestL[0],
    &footL[LEFT_LED][0],
    &footL[RIGHT_LED][0],
};
};

#endif
