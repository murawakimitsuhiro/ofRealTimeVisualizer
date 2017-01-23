//
//  Wave.hpp
//  firstPractice
//
//  Created by Murawaki on 2016/12/06.
//
//
#pragma once

#include "common.h"

#include "ofxAnimatableFloat.h"
#include "ofxAnimatableOfColor.h"
#include "ofxGui.h"
#include "DebugOutput.hpp"
#include "ofxEasyFft.h"

#ifndef WaveVboController_hpp
#define WaveVboController_hpp

class WaveVboController{
    class StaringPoint{
    private:
        ofVec2f point;
        float height;
        float radius;
        float speedCoefficient;
        
        float gradients;
        ofFloatColor color;
        ofxAnimatableFloat animate;
        ofxAnimatableOfColor colorAnimate;
        
    public:
        StaringPoint(ofVec2f point, float height, float radius, ofFloatColor color, float speed, WaveVboController* controller);
        void update(WaveVboController*);
        float planeDistance(ofPoint);
    };
private:
    ofSize size;
    ofPoint point;
    ofFloatColor baseColor;
    ofVec3f *locationVectors;
    ofVec3f *velocityVectors;
    ofFloatColor *colors;
    
    std::vector<StaringPoint> staringPoints;
    
    ofxEasyFft* fft;
    ofVbo* vbo;
    DebugOutput* debug;
    
public:
    WaveVboController(){};
    WaveVboController(ofSize, ofFloatColor, ofxEasyFft&, ofVbo&, DebugOutput&);
    void update();
    void draw();
    
    void updateLocation();
    void emitStaringPoint(ofVec2f point, float height, float radius, ofFloatColor color, float speed);
};

#endif /* WaveVboController_hpp */
