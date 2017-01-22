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
    
private:
	ofEasyCam cam;
	ofVbo myVbo;
    DebugOutput debugOutput;
    WaveVboController wave;
};

#endif /* WaveScene_hpp */
