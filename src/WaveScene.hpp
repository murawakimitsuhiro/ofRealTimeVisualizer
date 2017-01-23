//
//  WaveScene.hpp
//  firstPractice
//
//  Created by Murawaki on 2017/01/22.
//
//

#ifndef WaveScene_hpp
#define WaveScene_hpp

#include "common.h"

#include "ofxGui.h"
#include "DebugOutput.hpp"
#include "WaveVboController.hpp"

#define WAVE_WIDTH 200
#define WAVE_HEIGHT 200

class WaveScene : public baseScene {
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int);
    
    //TrigerKey And Action
    class WaveEmitKeyAction{
    public:
        int trigerKeyNum;
        ofxPanel emitSettingPanel;
        ofxLabel trigerKeyLabel;
        ofxFloatSlider height;
        ofxVec2Slider position;
        ofxFloatSlider radius;
        ofxFloatSlider speed;
        
        WaveEmitKeyAction(int);
        void pressedTrigerKey(WaveScene*);
    };
    
private:
    bool isSelectingTriger;
    
    //Graphics
	ofEasyCam cam;
	ofVbo myVbo;
    DebugOutput debugOutput;
    WaveVboController wave;
    vector <WaveEmitKeyAction *> waveEmitKeyActions;
    float avgSound;
    float* fftSmoothed;
    
    //UI
    ofxPanel mainPanel;
    ofxButton addButton;
    ofxPanel selectTrigerPanel;
    
    
    //func
    void displaySelectTrigerPanel();
    void addEmitKeyAction(int triger);
    
};

#endif /* WaveScene_hppk */
