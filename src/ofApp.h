#pragma once

#include "common.h"
#include "WaveVboController.hpp"
#include "ofxTween.h"

#define WAVE_WIDTH 200
#define WAVE_HEIGHT 200

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	void keyPressed  (int key);
    
private:
    DebugOutput debugOutput;
	ofEasyCam cam; // カメラ
	ofVbo myVbo; // VBO
    
    WaveVboController wave;
};
