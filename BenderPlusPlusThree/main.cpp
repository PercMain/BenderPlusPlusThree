//
//  main.cpp
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 4/8/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#include "SvgPacker.h"
#include "SpiralGenerator.h"
#include "GearGenerator.h"

using namespace std;

SvgPacker svg;
SpiralGenerator spiral(300);
GearGenerator gear();

int main(int argc, const char * argv[])
{
    vector<float> topTri = {200,20,130,150,270,150};
    
    vector<float> leftTri = {60,280,40,440,200,360};
    
    vector<float> rightTri = {340,280,200,360,360,440};
    
    vector<float> midPent = {130,150,60,280,200,360,340,280,270,150};
    
    svg.addToWork(spiral.generate(topTri));
    
    svg.addToWork(spiral.generate(leftTri));
    
    svg.addToWork(spiral.generate(rightTri));
    
    svg.addToWork(spiral.generate(midPent));
    
    svg.addToWork(svg.fileFooter());
    
    cout << svg.WorkingContent;
    return 0;
}

