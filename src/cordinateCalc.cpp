//
//  cordinateCalc.cpp
//  firstPractice
//
//  Created by Murawaki on 2017/01/18.
//
//

//#include "common.h"
#include "ofMain.h"

class cordinateMath{
public:
    static float distancece(ofVec3f a, ofPoint b){
        return sqrt(pow(b.x - a.x, 2) + pow(b.z - a.z, 2));
    }
    
    //return 'a' in "y = a*x^2 + b" from xIntercepts and yIntercepts
    static float gradientsOfQuadraticCurve(float xIntercepts, float yIntercepts){
        return -(yIntercepts/(xIntercepts*xIntercepts));
    }
    
private:
    cordinateMath();
};
