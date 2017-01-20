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
    public:
        StaringPoint(ofPoint point, float height, float radius, ofFloatColor color);
        void update(WaveVboController*);
        float planeDistance(ofPoint);
    };
private:
    ofSize size;
    ofPoint point;
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
