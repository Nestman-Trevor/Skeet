//
//  drops.h
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#ifndef __skeet__drops__
#define __skeet__drops__

#include <stdio.h>
#include "movable.h"

class Drop: public Movable
{
public:
    Drop() : Movable(), isAlive(false),
    redness(((float)(random(6, 10)))/10), dropSize(random(2, 6)){}
    
    bool getIsAlive() const {return isAlive;};
    void setIsAlive(bool dead) {isAlive = dead;};
    
    void addGravity();
    
    void draw() const;
    
private:
    bool isAlive;
    float redness;
    int dropSize;
};


#endif /* defined(__skeet__drops__) */
