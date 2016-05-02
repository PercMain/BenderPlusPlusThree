//
//  Bender.h
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 5/2/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#ifndef Bender_h
#define Bender_h

#include <iostream>
#include "SvgPacker.h"

class Bender
{
public:
    //Constructor
    Bender();
    
    string generateBend(double height, double width, int numberOfCuts);
};

#endif /* defined(__BenderPlusPlusThree__Bender__) */
