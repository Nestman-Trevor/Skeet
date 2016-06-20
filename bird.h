//
//  bird.h
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#ifndef __skeet__bird__
#define __skeet__bird__

#include <stdio.h>
#include "movable.h"

class Bird : public Movable
{
public:
    Bird() : Movable(), isDead(false){
        setX(-220);
        setY(random(-200, 200));
        if(getY() > 100)
        {
            setDx(5);
            setDy(random(-4, 1));
        }
        else if(getY() < -100)
        {
            setDx(5);
            setDy(random(0, 5));
        }
        else
        {
            setDx(5);
            setDy(random(-2, 3));
        }
    }
    Bird(int hp) : Movable(), isDead(false), hitPoints(hp){
        setX(-220);
        setY(random(-200, 200));
        if(getY() > 100)
        {
            setDx(5);
            setDy(random(-5, 0));
        }
        else if(getY() < -100)
        {
            setDx(5);
            setDy(random(0, 5));
        }
        else
        {
            setDx(5);
            setDy(random(-2, 2));
        }
    }
    virtual int getScoreValue() = 0;
    
    bool getIsDead() const {return isDead;};
    
    void setDead();
    int hitBird();
    
protected:
    bool isDead;
    int hitPoints;
    
private:
    bool checkIfDead();
    
};

#endif /* defined(__skeet__bird__) */
