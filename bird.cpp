//
//  bird.cpp
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#include "bird.h"

void Bird::setDead()
{
    isDead = true;
}

int Bird::hitBird()
{
    hitPoints--;
    if(checkIfDead())
    {
        isDead = true;
        return getScoreValue();
    }
    else
        return 0;
}

bool Bird::checkIfDead()
{
    if (hitPoints < 1)
        return true;
    else
        return false;
};