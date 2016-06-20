//
//  drops.cpp
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#include "drop.h"

void Drop::draw()const
{
    //std::cout<< "\nPre draw";
    for(int i = dropSize; i >= 2; i--)
    {
        drawRedCircle(velocity.getPoint(), i, redness);
        //std::cout << "\nDrawing drop";
    }
    drawRedDot(velocity.getPoint(), redness);
}

void Drop::addGravity()
{
    velocity.setDy(velocity.getDy() - .3);
}