#include "ofApp.h"

void ofApp::setup(){
    xmlSettings.loadFile("setting.xml");
    
    scenes.push_back(new WaveScene());
    scenes.push_back(new ParticleScene());
    scenes.push_back(new AudioVisualizerScene());
    currentSceneNum = 0;
    for (int i = 0; i<scenes.size(); i++){
        scenes[i]->setup();
    }
    
    soundStream.setup(this, 0, 1, 44100, 256, 4);
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

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    avgSound = 0.0;
    for (int i = 0; i < bufferSize; i++){
        avgSound += input[i]*input[i]; // 聴覚上は出力の2乗に比例するので、2乗しています。
    }
    avgSound /= bufferSize; // 平均を取ります。
    fftSmoothed = input;
    
    cout << nChannels << endl;
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
