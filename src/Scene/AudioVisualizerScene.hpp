#pragma once

#include "common.h"
#include "Looper.h"
#include "ofxEasyFft.h"

/*
#define WIDTH 1024
#define HEIGHT 768
#define HALF_WIDTH 512
#define HALF_HEIGHT 384
*/
 
#define PINK 196, 0, 118
#define PURPLE 76, 0, 183
#define TEAL 24, 178, 198
#define BLUE 10, 144, 209

#define NUM_STARS 100
#define STAR_ALPHA 0.5

class AudioVisualizerScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    void dragEvent(ofDragInfo dragInfo);
    void windowResized(int w, int h);
    void gotMessage(ofMessage msg);
    
    // Audio
    ofSoundPlayer music;
    float audioPan, audioPanMax;
    float avgSound;
    vector<float> fftSmoothed;
    vector<float> fftData;
    ofxEasyFft fft;
    vector<float> easyFftData;
    int nBandsToGet;
    
    // Drawing
    ofFbo bgFbo, scene, final;
    ofImage texture, noise;
    ofShader shader, texturizer, blur;
    float blurScale;
    
    // window State
    float width = 600;
    float height = 600;
    float halfWidth = 0;
    float halfHeight = 0;
    
    // Particles
    ofPolyline circle, tracer, wave;
    vector<ofPoint>stars;
    ofVbo starVbo;
    ofFbo starFbo;
    vector<Looper> loopers;
    
    // Interpolated values
    float count;
    float roll;
    ofColor background;
    ofColor rainbow;
    float hue;
    ofColor interp;
    float interpAmt;
    
    // Camera
    ofEasyCam cam;
};
