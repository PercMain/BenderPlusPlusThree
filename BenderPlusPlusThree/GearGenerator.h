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

struct gear_t
{
    int numberOfTeeth;
    float toothHeight;
    float rootRadius;
};

class GearGenerator
{
public:
    //Constructor
    GearGenerator();
    
    //Sets shaft diameter (and minimum gear diameter) for further calculations until changed
    void setShaftDiameter(float shaftDiameter);
    
    //Sets gear pitch
    void setGearPitch(int pitch);
    
    //Generates tooth counts from center to center distance and
    vector<int> calcToothCounts(float centerDistance, float desiredRatio);
    
    //Generates gear profile parameters based on distance from center to center
    //and desired gear ratio. Ratio is Driving:Driven. Return is <Driving, Driven>
    vector<gear_t> calculateTooth(float centerDistance, float desiredRatio);
    
    //Calls SvgPacker to draw completed gear
    string drawGear (gear_t profile);
    
    
private:
    //Pitch for gear system
    int _pitch;
    //Shaft Diameter
    float _shaftDiameter;
    //Temporary storage vector
    vector<float> _tempStorage;
    
};


#endif /* defined(__BenderPlusPlusThree__GearGenerator__) */
