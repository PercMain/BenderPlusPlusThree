//
//  Bender.cpp
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 5/2/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#include "Bender.h"

//Constructor
Bender::Bender()
{
}

float Bender::calcVerticalCutLengthScaling(float height)
{
    if(height >= (2 * defaultVerticalCutLength) + (3 * defaultVerticalSpacing))
    {
        verticalCutLengthScaling = 1.0f;
    }
    else
    {
        
        verticalCutLengthScaling = 1.0f /
            ((2 * defaultVerticalCutLength) + (3 * defaultVerticalSpacing)) / height;
    }
    return verticalCutLengthScaling;
}

//Uses the width and the number of desired cuts to calculate the spacing between cuts.
float Bender::calcCutSpacing(float width, int numberOfSegments)
{
    return width / numberOfSegments;
}