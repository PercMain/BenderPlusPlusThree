//
//  SpiralGenerator.cpp
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 4/26/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#include "SpiralGenerator.h"

//instance of SvgPacker used internally by SpiralGenerator
SvgPacker svgSpiralInternalInstance;

//How many spiral paths are drawn total, controls how "busy" the pattern appears
SpiralGenerator::SpiralGenerator(int density)
{
    _density = density;
}

//Generates spiral pattern from vector of bounding point coordinates
string SpiralGenerator::generate(vector<float> xy)
{
    /*
     *Determines point along edge that new line is drawn to
     *Ranges from 80 t0 95 percent of line length
     *Visually, this determines how "tight" the spiral appears
     */
    float Weighting = (rand() % 15 + 80) / 100.0;
    
    int i = 0;
    
    vector<float> Coords = xy;
    
    vector<float> NextXY;
    
    float XCalc;
    float YCalc;
    
    while (i < _density)
    {
        //finds new point some distance along next viable bounding line
        XCalc = (Coords[i] * Weighting) + (Coords[i + 2] * (1 - Weighting));
        YCalc = (Coords[i + 1] * Weighting) + (Coords[i + 3] * (1 - Weighting));
        
        NextXY = {XCalc, YCalc};
        
        //adds next point to coordinate vector
        Coords.insert(Coords.end(), NextXY.begin(), NextXY.end());
        
        i += 2;//increments coordinate count by 2 b/c coordinate vector is in formate X0,Y0,X1,Y1...Xn,Yn
    }
    
    return svgSpiralInternalInstance.poly(Coords);
    
}
