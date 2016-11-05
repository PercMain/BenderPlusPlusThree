//
//  Bender.h
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 5/2/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#ifndef Bender_h
#define Bender_h

#include <iostream>
#include "SvgPacker.h"

//To be determined experimentally
#define INCH_TO_NAT 1.0f

class Bender
{
public:
    //Constructor
    Bender(float startingX = 0.0f, float startingY = 0.0f);
    
    //Full bend geometry generator. Takes inputs of height and width of rectangular section
    //in inches and a number of segments. Returns a section of valid SVG code representing
    //the cut pattern to paste into documents.
    string generateBend(float height, float width, int numberOfSegments);
    
    //Uses a predefined scaling factor to turn input values in inches into native units for SVG format.
    float inchToNat(float inch);
    
    //Uses the height of the segment to calculate an ideal length for vertical cuts. Defaults are set
    //for various segment heights and this function determines whether or not these defaults will be
    //suitable for a given height before returning either the pre-set cut length or an edited one as needed.
    float calcVerticalCutLengthScaling(float height);
    
    //Uses the width and the number of desired cuts to calculate the spacing between cuts.
    float calcCutSpacing(float width, int numberOfSegments);
    
    //Adds an SVG Line to the file and moves the current cut coordinate from the start to the end
    void makeCut(float startX, float startY, float endX, float endY);
    
    //Moves the cut coordinate to skip over area covered by cut gap
    void makeGap(float length);
    
    //Uses makeCut and makeGap to draw a vertical series. Alternator is used to select
    //if the series is an even or odd numbered design.
    //(starting with a cut or starting with a gap)
    void makeSeries(float height, float horizontalCoordinate, bool alternator = true);
    
    
    
private:
    //defaults in inches
    float defaultVerticalCutLength;
    float defaultVerticalSpacing;
    
    //Coordinates of cut location
    float cutX;
    float cutY;
    
    float verticalCutLengthScaling = 1.0f;
    //float verticalCutSpacingScaling = 1.0f;
    
    
    
    
    
    
    
};

#endif /* defined(__BenderPlusPlusThree__Bender__) */
