//
//  ParticleSene.cpp
//  firstPractice
//
//  Created by Murawaki on 2017/01/23.
//
//

#include "ParticleScene.hpp"

void ParticleScene::setup(){
    isDisplayUI = true;
    // イベントリスナー
    num.addListener(this, &ParticleScene::onNumChanged);
    friction.addListener(this, &ParticleScene::onFrictionChanged);
    
    ofColor minColor = ofColor(0, 0, 0, 0);
    ofColor maxColor = ofColor(255, 255, 255, 255);
    
    // GUI
    gui.setup();
    gui.add(num.setup("particle number", 100000, 0, 200000));
    gui.add(size.setup("particle size", 1.0, 0.0, 3.0));
    gui.add(friction.setup("friction", 0.002, 0.0, 0.02));
    gui.add(attraction.setup("attraction", 0.1, 0.0, 1.0));
    gui.add(bgColor.setup("bg color", ofColor(0), minColor, maxColor));
    gui.add(fgColor.setup("fg color", ofColor(255), minColor, maxColor));
    
    // 保存したパラメータ読み込み
    gui.loadFromFile("settings.xml");
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(1.0);
    
    for (int i = 0; i < num; i++) {
        Particle p;
        p.friction = friction;
        p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        particles.push_back(p);
    }
}

//--------------------------------------------------------------
// イベントリスナー

// 摩擦を変更
void ParticleScene::onFrictionChanged(float &friction){
    for (int i = 0; i < particles.size (); i++) {
        particles[i].friction = friction;
    }
}

// パーティクルの数を変更
void ParticleScene::onNumChanged(int &num){
    // もしパーティクルの数が設定数よりも少ない場合
    if (num < particles.size()) {
        // パーティクルを削除
        for (int i = 0; i < particles.size() - num; i++) {
            particles.pop_back();
        }
    }
    // もしパーティクルの数が設定数よりも多い場合
    if (num > particles.size()) {
        // パーティクルを追加
        int addNum = num - particles.size();
        for (int i = 0; i < addNum; i++) {
            Particle p;
            p.friction = friction;
            p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
            particles.push_back(p);
        }
    }
}

//--------------------------------------------------------------
void ParticleScene::update(){
    // パーティクルの数だけ計算
    for (int i = 0; i < particles.size(); i++){
        // 力をリセット
        particles[i].resetForce();
        // もし引力がはたらいていたら
        if (atraction) {
            // マウスの位置に引力を加える
            particles[i].addAttractionForce(mousePoint.x, mousePoint.y, ofGetWidth(), attraction);
        }
        // パーティクル更新
        particles[i].update();
        // 画面の端にきたら反対側へ
        particles[i].throughOfWalls();
    }
}

//--------------------------------------------------------------
void ParticleScene::draw(){
    // 背景
    ofBackground(bgColor);
    
    // メッシュを点で描く
    mesh.clear();
    ofSetColor(fgColor);
    glPointSize(size);
    for (int i = 0; i < particles.size(); i++) {
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
    }
    mesh.draw();
    
    // 重力の点を描く
    if (atraction) {
        ofSetColor(255, 0, 0);
    } else {
        ofSetColor(0, 255, 255);
    }
    ofCircle(mousePoint.x, mousePoint.y, 4);
    
    if (isDisplayUI){
        gui.draw();
    }
}

//--------------------------------------------------------------
void ParticleScene::keyPressed(int key){
    baseScene::keyPressed(key);
    
    if (key == 'c') {
        particles.clear();
        for (int i = 0; i < num; i++) {
            Particle p;
            p.friction = 0.002;
            p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
            particles.push_back(p);
        }
    }
}

//--------------------------------------------------------------
void ParticleScene::mousePressed(int x, int y, int button){
    atraction = true;
}

//--------------------------------------------------------------
void ParticleScene::mouseReleased(int x, int y, int button){
    atraction = false;
}

void ParticleScene::mouseMoved(int x, int y){
    mousePoint = ofVec2f(x, y);
}
