#include "ofApp.h"

void ofApp::setup(){
    ofBackgroundHex(0x000000);
    cam.setDistance(100);
    
    this->wave = WaveVboController(ofSize(WAVE_WIDTH, WAVE_HEIGHT), ofFloatColor(0.5, 0.8, 1.0, 1.0), this->myVbo, this->debugOutput);
}

void ofApp::update(){
    
    debugOutput.setPropaty("FPS", ofToString(ofGetFrameRate(), 2));
    
    wave.update();
}

void ofApp::draw(){
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    cam.begin();
    glPointSize(0.5);
    myVbo.draw(GL_POINTS, 0, WAVE_WIDTH * WAVE_HEIGHT);
    cam.end();
    
    ofPopMatrix();
    
    debugOutput.drawPropaty();
}

void ofApp::keyPressed(int key){
    
    // fキーでフルスクリーン表示
    if (key == 'f') {
        ofToggleFullscreen();
    }
}
