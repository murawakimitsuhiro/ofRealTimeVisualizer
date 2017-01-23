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
    // パーティクルクラスをインスタンス化
    vector<Particle> particles;
    // メッシュ
    ofVboMesh mesh;
    // 引力が働いているか
    bool atraction;
    // パーティクルの数
    static const int NUM = 100000;
    
    ofVec2f mousePoint;
    
    // GUI
    ofxPanel gui;
    ofxIntSlider num;
    ofxFloatSlider size;
    ofxFloatSlider friction;
    ofxFloatSlider attraction;
    ofxColorSlider bgColor;
    ofxColorSlider fgColor;
    
    // イベントリスナー
    void onNumChanged(int &num);
    void onFrictionChanged(float &friction);
};

#endif /* ParticleSene_hpp */
