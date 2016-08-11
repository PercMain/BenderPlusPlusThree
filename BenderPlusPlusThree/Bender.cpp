//
//  Bender.cpp
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 5/2/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#include "Bender.h"

//Constructor
Bender::Bender(float startingX, float startingY)
{
    defaultVerticalCutLength = 2.0f;
    defaultVerticalSpacing = 0.25f;
    
    cutX = startingX;
    cutY = startingY;
    
    
}

//Full bend geometry generator. Takes inputs of height and width of rectangular section
//in inches and a number of segments. Returns a section of valid SVG code representing
//the cut pattern to paste into documents.
string Bender::generateBend(float height, float width, int numberOfSegments)
{
    float vertCutHeight = defaultVerticalCutLength * calcVerticalCutLengthScaling(height);
    float horizSpacing = calcCutSpacing(width, numberOfSegments);
    
    
    
    return ("<!--Non-Operational-->");
}

//Uses a predefined scaling factor to turn input values in inches into native units for SVG format.
float inchToNat(float inch)
{
    return inch * INCH_TO_NAT;
}


//Uses the height of the segment to calculate an ideal length for vertical cuts. Defaults are set
//for various segment heights and this function determines whether or not these defaults will be
//suitable for a given height before returning either the pre-set cut length or an edited one as needed.
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

