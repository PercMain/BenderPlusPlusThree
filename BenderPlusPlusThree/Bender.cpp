//
//  Bender.cpp
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 5/2/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#include "Bender.h"

//Instance of SvgPacker used internally by Bender
SvgPacker svgBenderInternalInstance;

//Constructor
Bender::Bender(float startingX, float startingY)
{
    defaultVerticalCutLength = 2.0f;    //  2 inches
    defaultVerticalSpacing = 0.25f;     //  1/4 inches
    
    cutX = startingX;
    cutY = startingY;
    
    
}

//Full bend geometry generator. Takes inputs of height and width of rectangular section
//in inches and a number of segments. Returns a section of valid SVG code representing
//the cut pattern to paste into documents.
string Bender::generateBend(float height, float width, int numberOfSegments)
{
    //Calls the scaling function to ensure a viable vertical cut length
    float vertCutHeight = defaultVerticalCutLength * calcVerticalCutLengthScaling(height);
    //Determines spacing between cut lines
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
    //Minimum height is 2 cut lengths and 3 gaps like so :_---_---_
    if(height >= (2 * defaultVerticalCutLength) + (3 * defaultVerticalSpacing))
    {
        verticalCutLengthScaling = 1.0f;
    }
    //if the piece is too small, make the scaling factor appropriately smaller
    //to fit the minimum requirements outlined above
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


//Adds an SVG Line to the file and moves the current cut coordinate from the start to the end
void Bender::makeCut(float startX, float startY, float endX, float endY)
{
    svgBenderInternalInstance.addToWork(svgBenderInternalInstance.line(startX, startY, endX, endY));
    cutX = endX;
    cutY = endY;
    
}

//Moves the cut coordinate to skip over area covered by cut gap
void Bender::makeGap(float length)
{
    cutY += length;
}

//Uses makeCut and makeGap to draw a vertical series. Alternator is used to select
//if the series is an even or odd numbered design.
//(starting with a cut or starting with a gap)
void Bender::makeSeries(float height, float horizontalCoordinate, bool alternator)
{
    float verticalCoordinate = 0;//set working vertical coordinate to top of work area
    bool internalAlternator = true;
    if(alternator)
    {
        if(internalAlternator)
        {
            makeGap(defaultVerticalSpacing);
            verticalCoordinate = cutY;
        }
    }
}


