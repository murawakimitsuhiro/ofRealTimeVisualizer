//
//  Wave.hpp
//  firstPractice
//
//  Created by Murawaki on 2016/12/06.
//
//
#pragma once

#include "common.h"

#ifndef WaveVboController_hpp
#define WaveVboController_hpp

class WaveVboController{
    /* 波の起点(ここのクラスで波の広がりの計算などを扱う */
    class StaringPoint{
    private:
        float existanceTime;
        Point point;
        float height;
        float radius;
        ofFloatColor color;
    public:
        StaringPoint(Point point, float height, float radius, ofFloatColor color);
        void update();
    };
    
private:
    ofSize size; /*size.heightはz軸方向の長さを示す*/
    Point point;
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
    void emitStaringPoint(Point point, float height, float radius, ofFloatColor color);
};

#endif /* WaveVboController_hpp */
