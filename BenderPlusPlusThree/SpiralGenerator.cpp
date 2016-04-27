//
//  SpiralGenerator.cpp
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 4/26/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#include "SpiralGenerator.h"

SvgPacker svgSpiralInternalInstance;


SpiralGenerator::SpiralGenerator(int density)
{
    _density = density;
}

string SpiralGenerator::generate(vector<float> xy)
{
    float Weighting = (rand() % 15 + 80) / 100.0;
    
    int i = 0;
    
    vector<float> Coords = xy;
    
    vector<float> NextXY;
    
    float XCalc;
    float YCalc;
    
    while (i < _density)
    {
        XCalc = (Coords[i] * Weighting) + (Coords[i + 2] * (1 - Weighting));
        YCalc = (Coords[i + 1] * Weighting) + (Coords[i + 3] * (1 - Weighting));
        
        NextXY = {XCalc, YCalc};
        
        Coords.insert(Coords.end(), NextXY.begin(), NextXY.end());
        
        i += 2;
    }
    
    return svgSpiralInternalInstance.poly(Coords);
    
}
