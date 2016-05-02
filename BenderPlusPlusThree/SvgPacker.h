//
//  SvgPacker.h
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 4/26/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#ifndef SvgPacker_h
#define SvgPacker_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <math.h>

#define PI 3.14159265


using namespace std;

class SvgPacker
{
public:
    //Constructor
    SvgPacker();
    
    //
    // Tag and content generation
    //
    
    //SVG boiler plate info.
    string fileHeader();
    string fileFooter();
    
    //Rotation transform opening tag and wrapper, takes angle and center of rotation
    string rotationHeader(float angle, float x, float y);
    string rotationWrap(string content, float angle, float x, float y);
    
    //pattern tag opening and wrapper. Takes width and height of base pattern
    string patternHeader(float width, float height);
    string patternWrap(string content, float width, float height);
    
    //returns <defs> or </defs> from true or false respectively. Wraps content
    string defsTag(bool openClose);
    string defsWrap(string content);
    
    //Creates line element from start and stop coordinates
    string line(float xStart, float yStart, float xStop, float yStop);
    
    //Creates circle element from radius and center coordinates
    string circle(float radius, float xCenter, float yCenter);
    
    //Creates arc element from radius, center coordinates, and angular limits
    string arc(float radius, float xCenter, float yCenter, float angleStart, float angleStop);
    
    //Creates quadratic bezier curve from start, stop and control point coordinates
    string quadBezier(float xStart, float yStart, float xStop, float yStop, float xControl, float yControl);
    
    //Creates polyline from coordinate vector
    string poly(vector<float> xy);
    
    //Creates a rotational pattern
    string rotationPattern(string content, int numberOfInstances, float xCenter, float yCenter);
    
    //Creates dashed perimeter circle
    string dashedCircle(float radius, float xCenter, float yCenter, float arcLength, int numberOfArcs, bool centerOnGap);
    
    //
    // Tag and content arrangement
    //
    
    //Adds to working file content before output to file
    void addToWork(string addition);
    
    //Internal string storage for any function. Make null after return
    void addToTemp(string addition);
    
    //
    // Public data
    //
    
    //Temporary storage for file content before output to file
    string WorkingContent;
    
private:
    
    string _TempContent;
};


#endif /* defined(__BenderPlusPlusThree__SvgPacker__) */
