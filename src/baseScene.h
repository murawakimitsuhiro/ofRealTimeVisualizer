//
//  baseScene.h
//  firstPractice
//
//  Created by Murawaki on 2017/01/22.
//
//

#ifndef baseScene_h
#define baseScene_h

#include "ofMain.h"

class baseScene {
public:
    
    virtual void setup(){};
    
    virtual void update(){};
    
    virtual void draw(){};
    
    virtual void keyPressed (int key){};
    
    virtual void keyReleased(int key){};
    
    virtual void mouseMoved(int x, int y ){};
    
    virtual void mouseDragged(int x, int y, int button){};
    
    virtual void mousePressed(int x, int y, int button){};
    
    virtual void mouseReleased(int x, int y, int button){};
    
    virtual void windowResized(int w, int h){};
    
};

#endif /* baseScene_h */
