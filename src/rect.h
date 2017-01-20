//
//  rect.h
//  firstPractice
//
//  Created by Murawaki on 2016/12/06.
//
//

#ifndef rect_h
#define rect_h

struct ofSize{
    int width;
    int height;
    
    ofSize(int w, int h){
        this->width = w;
        this->height = h;
    }
    
    ofSize(){
        this->width = 0;
        this->height = 0;
    }
    
    int getArea(){
        return this->width * this->height;
    }
};
/*
struct ofPoint{
    float x;
    float y;
    
    ofPoint(int x, int y){
        this->x = x;
        this->y = y;
    }
    
    ofPoint(){
        this->x = 0;
        this->y = 0;
    }
    
    float distance(ofPoint point){
        return sqrt(pow(this.x - ofPoint.x, 2) + pow(this.y - point.y, 2));
    }
};*/
#endif /* rect_h */
