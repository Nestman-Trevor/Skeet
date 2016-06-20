//
//  normal.cpp
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#include "normal.h"


void Normal::draw() const
{
    drawCircle(velocity.getPoint(), 20);
}