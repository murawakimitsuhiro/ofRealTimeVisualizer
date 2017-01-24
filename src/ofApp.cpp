#include "ofApp.h"

void ofApp::setup(){
    xmlSettings.loadFile("setting.xml");
    
    myFbo.allocate(640,480);
    myGlitch.setup(&myFbo);
    
    scenes.push_back(new WaveScene());
    scenes.push_back(new ParticleScene());
    scenes.push_back(new AudioVisualizerScene());
    
    currentSceneNum = 0;
    for (int i = 0; i<scenes.size(); i++){
        scenes[i]->setup();
    }
}

void ofApp::update(){
    debugOutput.setPropaty("FPS", ofToString(ofGetFrameRate(), 2));
    //myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE,true);
    myGlitch.setFx(OFXPOSTGLITCH_TWIST, true);
    
    scenes[currentSceneNum]->update();
}

void ofApp::draw(){
    ofFill();
    scenes[currentSceneNum]->draw();
    
    myGlitch.generateFx();
    myFbo.draw(0,0);
    
    debugOutput.drawPropaty();
    
}

void ofApp::keyPressed(int key){
    cout << key << endl;
    
    if (key == ' ') {
        currentSceneNum++;
        currentSceneNum %= scenes.size();
     //   scenes[currentSceneNum]->setup();
    }
    
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
