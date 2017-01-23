#pragma once

#include "common.h"
#include "ofxXmlSettings.h"

//scenes
#include "WaveScene.hpp"
#include "ParticleScene.hpp"
#include "AudioVisualizerScene.hpp"

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
    void keyPressed (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
private:
   //scene
    vector <baseScene *> scenes;
    int currentSceneNum;
    
    DebugOutput debugOutput;
    ofxXmlSettings xmlSettings;
};
