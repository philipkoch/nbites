#include "VisionCalibration.hpp"
#include "Log.hpp"

namespace man {
namespace vision {
namespace calibration {

    const std::string nbites_dir() {
        const char * envVar = getenv("NBITES_DIR");
        if ( envVar ) {
            return std::string(envVar);
        } else {
            throw std::runtime_error("NBITES_DIR required for offline testing");
        }
    }

    const std::string colorParamsPath() {
#ifdef OFFLINE
        return nbites_dir() + nbl::SharedConstants::OFFLINE_COLOR_PARAMS_SUFFIX();
#else
        return nbl::SharedConstants::ONLINE_COLOR_PARAMS_PATH();
#endif
    }

    const std::string cameraOffsetsPath() {
#ifdef OFFLINE
        return nbites_dir() + nbl::SharedConstants::OFFLINE_CAMERA_OFFSET_SUFFIX();
#else
        return nbl::SharedConstants::ONLINE_COLOR_CALIBRATION_PATH();
#endif
    }

    CalibrationParams * parseOffsetsFromJSON(json::Object& object) {
        double d_roll = object["d_roll"].asNumber().asDouble();
        double d_tilt = object["d_tilt"].asNumber().asDouble();
        return new CalibrationParams(d_roll, d_tilt);
    }

    CalibrationParams * getSavedOffsets(const std::string& robotName, bool top,
                                        const std::string& string) {
        json::Value val = json::parse(string);

        if (val.asObject().find(robotName) != val.asObject().end()) {
            json::Object& parts = val.asObject()[robotName].asObject()[top ? "camera_TOP" : "camera_BOT"].asObject();
            return parseOffsetsFromJSON(parts);
        } else {
            NBL_ERROR("cannot find camera offsets for robot: %s", robotName.c_str() )
            return new CalibrationParams();
        }
    }

    CalibrationParams * getSavedOffsets(const std::string& robotName, bool top) {
        std::string contents;
        nbl::io::readFileToString(contents, cameraOffsetsPath() );
        return getSavedOffsets(robotName, top, contents);
    }

    json::Object serialize(CalibrationParams * params) {
        json::Object ret;
        ret["d_roll"] = json::Number(params->getRoll());
        ret["d_tilt"] = json::Number(params->getTilt());

        return ret;
    }

    static inline float color_normalize(double val) {
        float ret = (float) (val / 255) - 0.5f;
        NBL_ASSERT_GE(ret, -0.5f)
        NBL_ASSERT_LE(ret, 0.5f)
        return ret;
    }

#define get(obj, field) ( (float) obj[field].asNumber().asDouble())

    Colors * parseColorsFromJSON(json::Object& object) {
        Colors * ret = new Colors;

        {
            json::Object& green = object["green"].asObject();
            ret->green.load(get(green, "uAtY0"), get(green, "vAtY0"), get(green, "uAtY255"), get(green, "vAtY255"), get(green, "u_fuzzy_range"), get(green, "v_fuzzy_range"));
        }

        {
            json::Object& white = object["white"].asObject();
            ret->green.load(get(white, "uAtY0"), get(white, "vAtY0"), get(white, "uAtY255"), get(white, "vAtY255"), get(white, "u_fuzzy_range"), get(white, "v_fuzzy_range"));
        }

        json::Object& black = object["black"].asObject();
        ret->orange.load(get(black, "uAtY0"), get(black, "vAtY0"), get(black, "uAtY255"), get(black, "vAtY255"), get(black, "u_fuzzy_range"), get(black, "v_fuzzy_range"));

        return ret;
    }

    Colors * getSavedColors(bool top, const std::string& string, json::Object * used) {
        json::Value val = json::parse(string);
        json::Object& obj = top ? val.asObject()["camera_TOP"].asObject() : val.asObject()["camera_BOT"].asObject();

        if (used) *used = obj;

        return parseColorsFromJSON(obj);
    }

    Colors * getSavedColors(bool top) {
        std::string contents;
        nbl::io::readFileToString(contents, colorParamsPath() );
        return getSavedColors(top, contents, NULL);
    }

//    json::Object serialize(ColorParams& params) {
//        json::Object ret;
//        ret["uAtY0"] = json::Number(params.)
//    }
//
//    json::Object serialize(Colors * colors) {
//        json::Object ret;
//
//        ret["green"] = serialize(colors->green);
//        ret["white"] = serialize(colors->white);
//        ret["black"] = serialize(colors->orange);
//
//        return ret;
//    }
}
}
}