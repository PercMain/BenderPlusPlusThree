//
//  GearGenerator.cpp
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 4/26/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#include "GearGenerator.h"

//Constructor
GearGenerator::GearGenerator(bool pressureAngleTwenty)
{
    //pressure angle true = 20, false = 14.5
    _pressureAngle = pressureAngleTwenty;
    _shaftDiameter = 5.0;
    _pitch = 20;
}

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

//Calculates gear information and returns gear_t with data
gear_t GearGenerator::generateGear(int numberOfTeeth)
{
    //Gear formulae from bostongear.com
    //Specifically Gear Theory PDF
    gear_t gear;
    
    gear.numberOfTeeth = numberOfTeeth;
    
    float pitchDiameter = numberOfTeeth / (float)_pitch;
    float rootRadius = (0.5)*pitchDiameter*cos(PI * _pressureAngle / 180.0);
    
    gear.rootRadius = rootRadius;
    
    float toothHeight;
    
    if (_pitch >= 20)//If pitch is 20 or finer
    {
        toothHeight = (2.2 / pitchDiameter) + 0.002;
    }
    else
    {
        toothHeight = 2.157 / pitchDiameter;
    }
    
    gear.toothHeight = toothHeight;
    
    return gear;
}
