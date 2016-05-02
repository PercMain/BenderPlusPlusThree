//
//  GearGenerator.cpp
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 4/26/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#include "GearGenerator.h"

//Constructor
GearGenerator::GearGenerator()
{}

//Sets shaft diameter (and minimum gear diameter) for further calculations until changed
void GearGenerator::setShaftDiameter(float shaftDiameter)
{
    _shaftDiameter = shaftDiameter;
}

//Sets gear pitch
void GearGenerator::setGearPitch(int pitch)
{
    _pitch = pitch;
}


//Generates gear profile parameters based on distance from center to center
//and desired gear ratio. Ratio is Driving:Driven. Return is <Driving, Driven>
vector<gear_t> GearGenerator::calculateTooth(float centerDistance, float desiredRatio)
{
    gear_t ret;
    ret.numberOfTeeth = 20;
    ret.toothHeight = 3;
    ret.rootRadius = 20;
    
    return {ret,ret};
}
