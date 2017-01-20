//
//  debugOutput.cpp
//  firstPractice
//
//  Created by Murawaki on 2016/12/08.
//
//

#include "DebugOutput.hpp"

void DebugOutput::setPropaty(std::string name, std::string value){
    propaty[name] = value;
}

void DebugOutput::drawPropaty(){
    std::string infoText = "";
    
    for(auto itr = propaty.begin(); itr != propaty.end(); ++itr) {
        infoText += "\n" + itr->first + " : " + itr->second;
    }
    
    if (isOutput){
        ofDrawBitmapString(infoText, 30, 30);
    }
}
