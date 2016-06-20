//
//  normal.h
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#ifndef __skeet__normal__
#define __skeet__normal__

#include <stdio.h>
#include "bird.h"

class Normal : public Bird
{
public:
    Normal() : Bird(1), scoreValue(10) {};
    
    virtual int getScoreValue() {return scoreValue;}
    
    void draw() const;
    
protected:

private:
    int scoreValue;
    
};

#endif /* defined(__skeet__normal__) */
