//
//  WaveVboController.cpp
//  firstPractice
//
//  Created by Murawaki on 2016/12/06.
//
//

#include "WaveVboController.hpp"

#include "ofMain.h"

WaveVboController::WaveVboController(ofSize meshSize, ofFloatColor color, ofVbo &vbo, DebugOutput &debugTarget){
    this->size = meshSize;
    this->locationVectors = new ofVec3f[meshSize.getArea()];
    this->velocityVectors = new ofVec3f[meshSize.getArea()];
    this->colors = new ofFloatColor[meshSize.getArea()];
    this->staringPoints = {};
    this->vbo = &vbo;

    this->debug = &debugTarget;
    
    for (int i = 0; i < size.width; i++) {
        for (int j = 0; j < size.height; j++) {
            float x = i - size.width/2;
            float y = 0;
            float z = j - size.height/2;
            locationVectors[j * size.width + i] = ofVec3f(x, y, z);
            
            colors[j * size.width + i].set(0.5, 0.8, 1.0, 1.0);
        }
    }
    
    vbo.setVertexData(locationVectors, size.getArea(), GL_DYNAMIC_DRAW);
    vbo.setColorData(colors, size.getArea(), GL_DYNAMIC_DRAW);
}

void WaveVboController::update(){
    debug->setPropaty("vertexNum", ofToString(size.width*size.height, 0));
    
    updateLocation();
}

void WaveVboController::updateLocation(){
    for (int i = 0; i < size.width; i++) {
        for (int j = 0; j < size.height; j++) {
            //ここの点を制御
            locationVectors[j * size.width + i] += velocityVectors[j * size.width + i];
        }
    }
    
    vbo->updateVertexData(locationVectors, size.getArea());
}

void WaveVboController::emitStaringPoint(Point point, float height, float radius, ofFloatColor color){
}

WaveVboController::StaringPoint::StaringPoint(Point point, float height, float radius, ofFloatColor color){
    this->point = point;
    this->height = height;
    this->radius = radius;
    this->color = color;
    
    this->existanceTime = height;
}

void WaveVboController::StaringPoint::update(){
    //影響のあるポイントとその値をセットする(べき)
    
   
    this->existanceTime -= 1.0;
}
