//
//  WaveVboController.cpp
//  firstPractice
//
//  Created by Murawaki on 2016/12/06.
//
//

#include "WaveVboController.hpp"

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
    
    for (int i=0; i<staringPoints.size(); i++){
        staringPoints[i].update(this);
    }
    
    vbo->updateVertexData(locationVectors, size.getArea());
}

void WaveVboController::emitStaringPoint(ofPoint point, float height, float radius, ofFloatColor color){
    staringPoints.push_back(StaringPoint(point, height, radius, color));
}

WaveVboController::StaringPoint::StaringPoint(ofPoint point, float height, float radius, ofFloatColor color){
    this->point = point;
    this->height = height;
    this->radius = radius;
    this->gradients = cordinateMath::gradientsOfQuadraticCurve(radius, height);
    this->color = color;
    
    animate.reset(0);
    animate.setDuration(0.01 * height);
    animate.setCurve(BOUNCE_IN_CUSTOM);
    animate.setRepeatType(LOOP_BACK_AND_FORTH_ONCE);
    animate.animateTo(height);
}

void WaveVboController::StaringPoint::update(WaveVboController* controller){
    animate.update(1.0f/60.0f);
    
    for (int i = 0; i < controller->size.width; i++) {
        for (int j = 0; j < controller->size.height; j++) {
            const int currentPointNum = j * controller->size.width + i;
            const float distanceFromStaring = cordinateMath::distancece(controller->locationVectors[currentPointNum], this->point);
            
            if (distanceFromStaring < radius){
                const float cordinateY = gradients * distanceFromStaring * distanceFromStaring + height;
                const float ratioHeight = cordinateY / height;
                controller->locationVectors[currentPointNum].y = animate.getCurrentValue() * ratioHeight;
            }
        }
    }
    
    if (animate.hasFinishedAnimating()) {
        controller->staringPoints.pop_back();
    }
}

float WaveVboController::StaringPoint::planeDistance(ofPoint point){
    return sqrt(pow(this->point.x - point.x, 2) + pow(this->point.y - point.y, 2));
}
