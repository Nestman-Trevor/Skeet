//
//  bullet.h
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#ifndef __skeet__bullet__
#define __skeet__bullet__

#include <stdio.h>
#include "movable.h"


class Bullet : public Movable
{
public:
    Bullet() : Movable(), isAlive(false), bulletSpeed(90) {};
    
    int getBulletSpeed()            {return bulletSpeed;};
    bool getIsAlive() const         {return isAlive;};
    
    void setIsAlive(bool isAlive)   {this->isAlive = isAlive;};
    
    void fire(int angle, int type);
    void draw() const               {drawDot(velocity.getPoint());};
    void drawType(int type) const;
    
private:
    bool isAlive;
    int bulletSpeed;
    
};

#endif /* defined(__skeet__bullet__) */
