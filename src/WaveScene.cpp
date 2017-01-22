//
//  WaveScene.cpp
//  firstPractice
//
//  Created by Murawaki on 2017/01/22.
//
//

#include "WaveScene.hpp"

void WaveScene::setup(){
    ofBackgroundHex(0x000000);
    cam.setDistance(100);
    
    this->wave = WaveVboController(ofSize(WAVE_WIDTH, WAVE_HEIGHT), ofFloatColor(0.5, 0.8, 1.0, 1.0), this->myVbo, this->debugOutput);
}

void WaveScene::update(){
    wave.update();
}

void WaveScene::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    cam.begin();
    glPointSize(0.5);
    myVbo.draw(GL_POINTS, 0, WAVE_WIDTH * WAVE_HEIGHT);
    cam.end();
    
    ofPopMatrix();
}

void WaveScene::keyPressed(int key){
    
}
