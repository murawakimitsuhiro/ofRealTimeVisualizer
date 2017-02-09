//
//  ParticleSene.hpp
//  firstPractice
//
//  Created by Murawaki on 2017/01/23.
//
//

#ifndef ParticleScene_hpp
#define ParticleScene_hpp

#include "common.h"
#include "ofxGui.h"
#include "Particle.h"
#include "ofxPostGlitch.h"

class ParticleScene: public baseScene{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseMoved(int x, int y );
    
private:
    // „Éë„Éº„ÉÜ„Ç£„ÇØ„É´„ÇØ„É©„Çπ„Çí„Ç§„É≥„Çπ„Çø„É≥„ÇπÂåñ
    vector<Particle> particles;
    // „É°„ÉÉ„Ç∑„É•
    ofVboMesh mesh;
    // ÂºïÂäõ„ÅåÂÉç„ÅÑ„Å¶„ÅÑ„Çã„Åã
    bool atraction;
    // „Éë„Éº„ÉÜ„Ç£„ÇØ„É´„ÅÆÊï∞
    static const int NUM = 100000;
    
    ofVec2f mousePoint;
    
    ofFbo myFbo;
    ofxPostGlitch myGlitch;
    
    // GUI
    ofxPanel gui;
    ofxIntSlider num;
    ofxFloatSlider size;
    ofxFloatSlider friction;
    ofxFloatSlider attraction;
    ofxColorSlider bgColor;
    ofxColorSlider fgColor;
    
    // „Ç§„Éô„É≥„Éà„É™„Çπ„Éä„Éº
    void onNumChanged(int &num);
    void onFrictionChanged(float &friction);
};

#endif /* ParticleSene_hpp */
