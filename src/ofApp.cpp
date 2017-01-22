#include "ofApp.h"

void ofApp::setup(){
    xmlSettings.loadFile("setting.xml");
    
    scenes.push_back(new WaveScene());
    currentSceneNum = 0;
    scenes[currentSceneNum]->setup();
}

void ofApp::update(){
    debugOutput.setPropaty("FPS", ofToString(ofGetFrameRate(), 2));
    
    scenes[currentSceneNum]->update();
}

void ofApp::draw(){
    scenes[currentSceneNum]->draw();
    
    debugOutput.drawPropaty();
}

void ofApp::keyPressed(int key){
    cout << key << endl;
    
    if (key == 'f') {
        ofToggleFullscreen();
    }
    
    scenes[currentSceneNum]->keyPressed(key);
}

void ofApp::keyReleased(int key){
    
    scenes[currentSceneNum]->keyReleased(key);
    
}

void ofApp::mouseMoved(int x, int y ){
    
    scenes[currentSceneNum]->mouseMoved(x, y);
    
}

void ofApp::mouseDragged(int x, int y, int button){
    
    scenes[currentSceneNum]->mouseDragged(x, y, button);
    
}

void ofApp::mousePressed(int x, int y, int button){
    
    scenes[currentSceneNum]->mousePressed(x, y, button);
    
}

void ofApp::mouseReleased(int x, int y, int button){
    
    scenes[currentSceneNum]->mouseReleased(x, y, button);
    
}

void ofApp::windowResized(int w, int h){
    
    scenes[currentSceneNum]->windowResized(w, h);
    
}
