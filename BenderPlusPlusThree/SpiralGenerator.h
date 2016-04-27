//
//  SpiralGenerator.h
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 4/26/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#ifndef __BenderPlusPlusThree__SpiralGenerator__
#define __BenderPlusPlusThree__SpiralGenerator__

#include <iostream>
#include "SvgPacker.h"//Required for operation

class SpiralGenerator
{
public:
    //Constructor
    SpiralGenerator(int density);
    
    //Generates spiral pattern from vector of bounding point coordinates
    string generate(vector<float> xy);
    
private:
    //How many soiral paths are drawn total, controls how "busy" the pattern appears
    int _density;
    
};


#endif /* defined(__BenderPlusPlusThree__SpiralGenerator__) */
