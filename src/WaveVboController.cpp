//
//  WaveVboController.cpp
//  firstPractice
//
//  Created by Murawaki on 2016/12/06.
//
//

#include "WaveVboController.hpp"

WaveVboController::WaveVboController(ofSize meshSize, ofFloatColor color, ofxEasyFft &fft,ofVbo &vbo, DebugOutput &debugTarget){
    this->size = meshSize;
    this->baseColor = ofFloatColor(0.5, 0.8, 1.0, 1.0);
    this->locationVectors = new ofVec3f[meshSize.getArea()];
    this->velocityVectors = new ofVec3f[meshSize.getArea()];
    this->colors = new ofFloatColor[meshSize.getArea()];
    
    this->staringPoints = {};
    
    this->fft = &fft;
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
    
    vector<float> buffer;
    buffer = fft->getBins();
    /*for (int i=0; i<size.width*size.height; i++){
        if (i < size.width){
            locationVectors[i].y = buffer[i] * 50;
        }else{
            locationVectors[i].y = locationVectors[i-size.width].y;
        }
    }*/
    for (int i=size.width*size.height-1; i>=0; i--){
        if (i < size.width){
            locationVectors[i].y = buffer[i] * 50;
        }else{
            locationVectors[i].y = locationVectors[i-size.width].y;
        }
    }
    
    if (updateCount == size.width-1){
        updateCount = 1;
    }else{
        updateCount++;
    }
    
    for (int i=0; i<staringPoints.size(); i++){
        staringPoints[i].update(this);
    }
    
    vbo->updateVertexData(locationVectors, size.getArea());
}

void WaveVboController::emitStaringPoint(ofVec2f point, float height, float radius, ofFloatColor color, float spped){
    staringPoints.push_back(StaringPoint(point, height, radius, color, spped, this));
}

WaveVboController::StaringPoint::StaringPoint(ofVec2f point, float height, float radius, ofFloatColor color,float speed, WaveVboController* controller){
    this->point = point;
    this->height = height;
    this->radius = radius;
    this->speedCoefficient = speed;
    this->gradients = cordinateMath::gradientsOfQuadraticCurve(radius, height);
    this->color = color;
    
    const float animDuration = 0.01 * height * speedCoefficient;
    const AnimCurve animCurve = BOUNCE_IN_CUSTOM;
    const AnimRepeat animRepeat = LOOP_BACK_AND_FORTH_ONCE;
    
    animate.reset(0);
    animate.setDuration(animDuration);
    animate.setCurve(animCurve);
    animate.setRepeatType(animRepeat);
    animate.animateTo(height);
    
    colorAnimate.setColor(controller->baseColor);
    colorAnimate.setDuration(animDuration);
    colorAnimate.setCurve(animCurve);
    colorAnimate.setRepeatType(animRepeat);
    colorAnimate.animateToIfFinished(color);
}

void WaveVboController::StaringPoint::update(WaveVboController* controller){
    animate.update(1.0f/60.0f);
    colorAnimate.update(1.0f/60.0f);
    
    for (int i = 0; i < controller->size.width; i++) {
        for (int j = 0; j < controller->size.height; j++) {
            const int currentNum = j * controller->size.width + i;
            const float distanceFromStaring = cordinateMath::distancece(controller->locationVectors[currentNum], this->point);
            
            if (distanceFromStaring < radius){
                const float cordinateY = gradients * distanceFromStaring * distanceFromStaring + height;
                const float ratioHeight = cordinateY / height;
                
                controller->colors[currentNum] = colorAnimate.getCurrentColor();
                controller->locationVectors[currentNum].y = animate.getCurrentValue() * ratioHeight;
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
