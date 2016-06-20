//
//  bullet.cpp
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#include "bullet.h"

void Bullet::fire(int angle, int type)
{
     switch (type) {
        case 0:
            setX(200);
            setY(-200);
            setDx(((float)-(90 - angle))/5);
            setDy(((float)(angle))/5);
            break;
        case 1:
            setX(200);
            setY(-200);
            setDx(((float)-(90 - angle + (random(-5, 6))))/5);
            setDy(((float)(angle + (random(-5, 6))))/5);
            break;
        default:
            break;
    }
    
}

void Bullet::drawType(int type) const
{
    switch (type) {
        case 0:
            drawDot(velocity.getPoint());
            break;
        case 1:
            drawDot(velocity.getPoint());
            break;
        default:
            break;
    }
}