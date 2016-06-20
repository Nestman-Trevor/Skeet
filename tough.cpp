//
//  tough.cpp
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#include "tough.h"

void Tough::draw() const
{
    drawCircle(velocity.getPoint(), 20);
    if (hitPoints > 0)
        drawNumber(velocity.getPoint(), hitPoints);
}