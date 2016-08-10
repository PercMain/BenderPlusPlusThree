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

class Bender
{
public:
    //Constructor
    Bender();
    
    //Full bend geometry generator. Takes inputs of height and width of rectangular section
    //in inches and a number of segments. Returns a section of valid SVG code representing
    //the cut pattern to paste into documents.
    string generateBend(float height, float width, int numberOfSegments);
    
    //Uses a predefined scaling factor to turn input values in inches into native units for SVG format.
    float inchToNat(float inch);
    
    //Uses the height of the segment to calculate an ideal length for vertical cuts. Defaults are set
    //for various segment heights and this function determines whether or not these defaults will be
    //suitable for a given height before returning either the pre-set cut length or an edited one as needed.
    float calcVerticalCutLength(float height);
    
    //Uses the width and the number of desired cuts to calculate the spacing between cuts.
    float calcCutSpacing(float width, int numberOfSegments);
    
    
    
private:
    float defaultVerticalCutLength;
    float defaultVerticalSpacing;
    
    float verticalCutLengthScaling = 1.0f;
    float verticalCutSpacingScaling = 1.0f;
    
    
    
    
    
};

#endif /* defined(__BenderPlusPlusThree__Bender__) */
