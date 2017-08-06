#include "ofApp.h"

void ofApp::setup(){
    xmlSettings.loadFile("setting.xml");
    
    scenes.push_back(new AudioVisualizerScene());
    scenes.push_back(new ParticleScene());
    scenes.push_back(new WaveScene());
    scenes.push_back(new MidiEffectsScene());
    
    currentSceneNum = 0;
    for (int i = 0; i<scenes.size(); i++){
        /*ShpereVisulaliserScene *shpere = dynamic_cast<ShpereVisulaliserScene *>(scenes[i]);
        if (shpere != NULL) {
            shpere->setup(*this);
        } else {*/
            scenes[i]->setup();
        //}
    }
}

void ofApp::setupInspector() {
    ofSetBackgroundColor(0.87, 0.87, 0.87);
}

void ofApp::update(){
    debugOutput.setPropaty("FPS", ofToString(ofGetFrameRate(), 2));
    scenes[currentSceneNum]->update();
}

void ofApp::draw(){
    scenes[currentSceneNum]->draw();
    
    debugOutput.drawPropaty();
}

void ofApp::drawInspector(ofEventArgs &args) {
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
