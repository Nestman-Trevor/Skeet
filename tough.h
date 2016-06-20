//
//  tough.h
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#ifndef __skeet__tough__
#define __skeet__tough__
#include <stdio.h>
#include "bird.h"

class Tough : public Bird
{
public:
    Tough() : Bird(3), scoreValue(50) {};
    
    virtual int getScoreValue() {return scoreValue;}
    
    void draw() const;
    
protected:
    
private:
    int scoreValue;
    
};

#endif /* defined(__skeet__tough__) */
