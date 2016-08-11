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
//#include "Bender.h"

using namespace std;

SvgPacker svg;
SpiralGenerator spiral(100);
GearGenerator gear();
//Bender bend();
// Test


int main(int argc, const char * argv[])
{
    //vector<double> topTri = {200,20,130,150,270,150};
    //svg.addToWork(spiral.generate(topTri));

    //vector<double> leftTri = {60,280,40,440,200,360};
    //svg.addToWork(spiral.generate(leftTri));

    //vector<double> rightTri = {340,280,200,360,360,440};
    //svg.addToWork(spiral.generate(rightTri));

    
    vector<double> midPent = {130,130,70,260,200,360,330,260,270,130};
    
    
    svg.addToWork(svg.nGon(midPent));
    
    svg.addToWork(spiral.generate(midPent));
    
    
    svg.addToWork(svg.fileFooter());
    
    cout << svg.WorkingContent;
    
    svg.publish("test6.svg");
    
    return 0;
}



