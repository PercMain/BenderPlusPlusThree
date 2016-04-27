//
//  GearGenerator.h
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 4/26/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#ifndef __BenderPlusPlusThree__GearGenerator__
#define __BenderPlusPlusThree__GearGenerator__

#include <iostream>
#include "SvgPacker.h"

struct gearTooth_t
{
    int numberOfTeeth;
    float toothHeight;
    float rootRadius;
};

class GearGenerator
{
public:
    //Constructor
    GearGenerator(int pitch);
    
    //Generates gear profile parameters based on distance from center to center
    //and desired gear ratio. Ratio is Driving:Driven. Return is <Driving, Driven>
    vector<gearTooth_t> calculateTooth(float centerDistance, float desiredRatio);
    
    //Calls SvgPacker to draw completed gear
    string drawGear (gearTooth_t profile);
    
    
private:
    //Pitch for gear system
    int _pitch;
    //Temporary storage vector
    vector<float> _tempStorage;
    
};


#endif /* defined(__BenderPlusPlusThree__GearGenerator__) */
