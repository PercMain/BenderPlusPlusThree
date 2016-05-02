//
//  SvgPacker.cpp
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 4/26/16.
//  Copyright (c) 2016 Ben Lewson. All rights reserved.
//

#include "SvgPacker.h"

#define PI 3.14159265

//Constructor
SvgPacker::SvgPacker()
{
    WorkingContent = SvgPacker::fileHeader();
}

string SvgPacker::fileHeader()
{
    return
    "<?xml version=\"1.0\" standalone=\"no\"?>\n"
    "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n"
    "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n"
    "<svg width=\"100cm\" height=\"100cm\" viewBox=\"0 0 1000 1000\" version=\"1.1\"\n"
    "xmlns=\"http://www.w3.org/2000/svg\">\n";
}

string SvgPacker::fileFooter()
{
    return "</svg>\n";
}

//Returns the opening tags to a rotation transform
string SvgPacker::rotationHeader(float angle, float xCenter, float yCenter)
{
    
    string LineStart = "<g id=\"GearTooth\" transform=\"rotate(";
    string LineEnd = ")\" x=\"0\" y=\"0\">\n";
    string Angle = to_string(angle);
    string XCenter = to_string(xCenter);
    string YCenter = to_string(yCenter);
    
    return LineStart + Angle + " " + XCenter + " " + YCenter + LineEnd;
    
}

//Wraps content in rotation transform tags
string SvgPacker::rotationWrap(string content, float angle, float xCenter, float yCenter)
{
    return rotationHeader(angle, xCenter, yCenter) + content + "</g>\n";
}

//Returns opening tag for pattern
string SvgPacker::patternHeader(float width, float height)
{
    //<pattern id="TrianglePattern" patternUnits="userSpaceOnUse"
    //x="0" y="0" width="20" height="10"
    //viewBox="0 0 20 10" >
    
    string LineStart = "<pattern id=\"B++\" patternUnits=\"userSpaceOnUse\" x=\"0\" y=\"0\" width=\"";
    string Second = "\" height=\"";
    string Third = "\" viewBox=\"0 0 ";
    
    string Width = to_string(width);
    string Height = to_string(height);
    
    return LineStart + Width + Second + Height + Third + Width + " " + Height + "\" >\n";
}

//Wraps in pattern tags
string SvgPacker::patternWrap(string content, float width, float height)
{
    return patternHeader(width, height) + content + "</pattern>\n";
}

//Returns opening (true) or closing (false) <defs> tag. Necesarry surrounding pattern tags
string SvgPacker::defsTag(bool openClose)
{
    if (openClose)
    {
        return "<defs>\n";
    }
    else
    {
        return "</defs>\n";
    }
}

//Wraps in <defs> tags
string SvgPacker::defsWrap(string content)
{
    return defsTag(true) + content + defsTag(false);
}

//Returns line tags with coordinate data
string SvgPacker::line(float xStart, float yStart, float xStop, float yStop)
{
    string LineStart = "<line x1=\"";
    string Second = "\" y1=\"";
    string Third = "\" x2=\"";
    string Fourth = "\" y2=\"";
    string LineEnd = "\" stroke=\"black\" stroke-width=\"0.1\" />\n";
    
    string XStart = to_string(xStart);
    string YStart = to_string(yStart);
    string XStop = to_string(xStop);
    string YStop = to_string(yStop);
    
    return LineStart + XStart + Second + YStart + Third + XStop + Fourth + YStop + LineEnd;
    
}

//Returns circle of given radius centered at coordinates
string SvgPacker::circle(float radius, float xCenter, float yCenter)
{
    //<circle cx="50" cy="50" r="40" stroke="black" stroke-width="3" fill="red" />
    string LineStart = "<circle cx=\"";
    string Second = "\" cy=\"";
    string Third = "\" r=\"";
    string LineEnd = "\" stroke=\"black\" stroke-width=\"0.1\" fill=\"none\" />\n";
    
    string Radius = to_string(radius);
    string XCenter = to_string(xCenter);
    string YCenter = to_string(yCenter);
    
    return LineStart + XCenter + Second + YCenter + Third + Radius + LineEnd;
    
}

//Creates polyline following coordinate vector
string SvgPacker::poly(vector<float> xy)
{
    _TempContent.clear();
    string LineStart = "<polyline points=\"";
    string LineEnd = "\" style=\"fill:none;stroke:black;stroke-width:0.1\" />\n\n";
    
    unsigned long NumberOfPoints = xy.size();
    
    for (int i = 0; i < NumberOfPoints; i+=2)
    {
        string OnePair = to_string(xy[i]) + ", " + to_string(xy[i+1]) + " \n";
        addToTemp(OnePair);
        
    }
    return LineStart + _TempContent + LineEnd;
    
}

//Generates circle segment centered at coordinates between angle start and stop
string SvgPacker::arc(float radius, float xCenter, float yCenter, float angleStart, float angleStop)
{
    string LineStart = "<path d=\"M ";
    string Second = " A ";
    string Third = " 0 0 1 ";
    string LineEnd = "\" stroke = \"black\" stroke-width = \"0.1\" fill = \"none\" />\n";
    
    float AngleOffset = -90;//sets 0 degrees vertical
    
    string XStart = to_string(radius * cosf((angleStart + AngleOffset)*PI/180) + xCenter);
    string YStart = to_string(radius * sinf((angleStart + AngleOffset)*PI/180) + yCenter);
    
    string XStop = to_string(radius * cosf((angleStop + AngleOffset)*PI/180) + xCenter);
    string YStop = to_string(radius * sinf((angleStop + AngleOffset)*PI/180) + yCenter);
    
    string XRadius = to_string(radius);
    string YRadius = XRadius;
    
    return  LineStart + XStart + " " + YStart
    + Second + XRadius + " " + YRadius
    + Third + XStop + " " + YStop
    + LineEnd;
}

//Creates a rotational pattern around a center
string SvgPacker::rotationPattern(string content, int numberOfInstances, float xCenter, float yCenter)
{
    _TempContent.clear();
    
    float Angle = 360.0/numberOfInstances;
    for (int i = 0; i < numberOfInstances; i++)
    {
        addToTemp(rotationWrap(content, i * Angle, xCenter, yCenter));
    }
    return _TempContent;
    
}

//Creates a dashed circle around center. Centers vertically on either gap or segment
string SvgPacker::dashedCircle(float radius, float xCenter, float yCenter,
                               float arcLength, int numberOfArcs, bool centerOnGap)
{
    _TempContent.clear();
    
    //Find the length of gaps between arc segements
    float GapLength = (360 - (arcLength * numberOfArcs)) / numberOfArcs;
    
    //If centerOnGap, then offset starting angle by half of gap arc
    float AngleInitial = centerOnGap * (GapLength / 2);
    
    
    for (int i = 0; i < numberOfArcs; i++)
    {
        float AngleStart = AngleInitial + ((arcLength + GapLength) * i);
        float AngleStop = AngleStart + arcLength;
        
        //add each arc to Temp
        addToTemp(arc(radius, xCenter, yCenter, AngleStart, AngleStop));
    }
    
    return _TempContent;
    
}

//adds content to temporary file
void SvgPacker::addToWork(string addition)
{
    WorkingContent += addition;
}

//Adds to _TempContent
void SvgPacker::addToTemp(string addition)
{
    _TempContent += addition;
}