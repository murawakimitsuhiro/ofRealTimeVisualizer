//
//  debugOutput.hpp
//  firstPractice
//
//  Created by Murawaki on 2016/12/08.
//
//

#ifndef DebugOutput_hpp
#define DebugOutput_hpp

#include "common.h"

class DebugOutput{
private:
    std::map<std::string, std::string> propaty;
public:
    DebugOutput(){};
    void setPropaty(std::string name, std::string value);
    void drawPropaty();
};

#endif /* ebugOutput_hpp */
