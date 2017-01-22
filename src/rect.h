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
#endif /* rect_h */
