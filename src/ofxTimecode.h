/**
 * ofxTimecode
 * James George 2012
 *
 * Created as part of the Duration + ofxTimeline project
 * Supported by YCAM InterLab Guest Research Project ( http://interlab.ycam.jp/en/ )
 *
 */

#pragma once

#include <cstdint>//"ofMain.h"
#include <string>

class ofxTimecode {
  public:
    ofxTimecode();
    
    void setFPS(float fps); //default is 30;
    float getFPS();
    
    //these functions expect format HH:MM:SS:MLS
    //and negative value if improperly formatted
	static uint64_t millisForTimecode(std::string timecode);
    static float secondsForTimecode(std::string timecode);

    int frameForTimecode(std::string timecode);
    int frameForSeconds(float timeInSeconds);
    int frameForMillis(uint64_t timeInMillis);    
    float secondsForFrame(int frame);
    uint64_t millisForFrame(int frame);

    static int frameForTimecode(std::string timecode, float fps);
    static int frameForSeconds(float timeInSeconds, float fps);
    static int frameForMillis(uint64_t timeInMillis, float fps);
    static float secondsForFrame(int frame, float fps);
    static uint64_t millisForFrame(int frame, float fps);
    
    //returns format HH:MM:SS:FR
    static std::string timecodeForMillis(uint64_t millis, std::string millisDelimiter = ":");
    static std::string timecodeForSeconds(float seconds, std::string millisDelimiter = ":");
    static std::string timecodeForFrame(int frame, float fps, std::string millisDelimiter = ":");
    std::string timecodeForFrame(int frame, std::string millisDelimiter = ":");
    
  protected:
    float fps;
    static bool decodeString(std::string time, int* times);
};
