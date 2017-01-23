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
    
    this->isSelectingTriger = false;
    this->isDisplayUI = true;
    this->wave = WaveVboController(ofSize(WAVE_WIDTH, WAVE_HEIGHT), ofFloatColor(0.5, 0.8, 1.0, 1.0), this->myVbo, this->debugOutput);
    
    mainPanel.setup();
    mainPanel.setPosition(ofGetWindowSize().x - mainPanel.getWidth(), 0);
    mainPanel.add(addButton.setup("Add EmitKeyAction"));
    addButton.addListener(this, &WaveScene::displaySelectTrigerPanel);
    
    selectTrigerPanel.setup();
    selectTrigerPanel.setPosition(ofGetWindowSize().x/2 - selectTrigerPanel.getWidth()/2,
                                  ofGetWindowSize().y/2 - selectTrigerPanel.getHeight()/2);
    selectTrigerPanel.add(new ofxLabel(std::string("Press Triger Key")));
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
    
    if (isDisplayUI){
        debugOutput.drawPropaty();
        mainPanel.draw();
        if (isSelectingTriger){
            selectTrigerPanel.draw();
        }
    }
    
    for (int i=0; i<waveEmitKeyActions.size(); i++){
        waveEmitKeyActions[i]->emitSettingPanel.draw();
    }
}

void WaveScene::keyPressed(int key){
    if (key == 'f'){
        isDisplayUI = !isDisplayUI;
        return;
    }
    
    if (isSelectingTriger){
        addEmitKeyAction(key);
        isSelectingTriger = false;
    }
    
    for (int i=0; i<waveEmitKeyActions.size(); i++){
        if (waveEmitKeyActions[i]->trigerKeyNum == key){
            waveEmitKeyActions[i]->pressedTrigerKey(this);
        }
    }
}

void WaveScene::displaySelectTrigerPanel(){
    isSelectingTriger = true;
}

void WaveScene::addEmitKeyAction(int triger){
    waveEmitKeyActions.push_back(new WaveEmitKeyAction(triger));
}

//MARK:- WaveEmitKeyAction
WaveScene::WaveEmitKeyAction::WaveEmitKeyAction(int trigerKeyNum){
    this->trigerKeyNum = trigerKeyNum;
    
    std::string trigerStr = "Triger : " + std::to_string(trigerKeyNum);
    emitSettingPanel.setup();
    emitSettingPanel.add(trigerKeyLabel.setup(trigerStr));
    emitSettingPanel.add(height.setup("height", 20, 1, 100));
    emitSettingPanel.add(radius.setup("raidus", 20, 1, 100));
    emitSettingPanel.add(speed.setup("speed", 1, 0, 10));
    emitSettingPanel.add(position.setup("emitPosition", ofVec2f(0, 0), ofVec2f(-100, -100), ofVec2f(100, 100)));
}

void WaveScene::WaveEmitKeyAction::pressedTrigerKey(WaveScene* scene){
    scene->wave.emitStaringPoint(position, height, radius, ofFloatColor(0, 0, 0, 1.0), speed);
}
