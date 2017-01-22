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

#ifndef WaveVboController_hpp
#define WaveVboController_hpp

class WaveVboController{
    class StaringPoint{
    private:
        ofPoint point;
        float height;
        float radius;
        float gradients;
        ofFloatColor color;
        ofxAnimatableFloat animate;
        ofxAnimatableOfColor colorAnimate;
    public:
        StaringPoint(ofPoint point, float height, float radius, ofFloatColor color, WaveVboController* controller);
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
    
    ofVbo* vbo;
    DebugOutput* debug;
    
public:
    WaveVboController(){};
    WaveVboController(ofSize, ofFloatColor, ofVbo&, DebugOutput&);
    void update();
    void draw();
    
    void updateLocation();
    void emitStaringPoint(ofPoint point, float height, float radius, ofFloatColor color);
};

#endif /* WaveVboController_hpp */
