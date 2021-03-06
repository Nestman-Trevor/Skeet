//
//  sacred.h
//  skeet
//
//  Created by Trevor on 3/16/15.
//  Copyright (c) 2015 Trevor. All rights reserved.
//

#ifndef __skeet__sacred__
#define __skeet__sacred__

#include <stdio.h>
#include "bird.h"

class Sacred : public Bird
{
public:
    Sacred() : Bird(1), scoreValue(-50) {};
    
    virtual int getScoreValue() {return scoreValue;}
    
    void draw() const;
    
protected:
    
private:
    int scoreValue;
    
};


#endif /* defined(__skeet__sacred__) */
