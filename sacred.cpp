//
//  sacred.cpp
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#include "sacred.h"

void Sacred::draw() const
{
    drawStar(velocity.getPoint(), 20, (int)velocity.getX());
}