//
//  Rabbit.cpp
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 11/5/16.
//  Copyright © 2016 Ben Lewson. All rights reserved.
//

#include "Rabbit.h"

//Instance of SvgPacker used internally by Rabbit
SvgPacker rabbitInternalInstance;

//Constructor
Rabbit::Rabbit(float thickness)
{
    _thickness = thickness;
}

string Rabbit::generate(float length, float width, float depth, int lidStyle)
{
    //Make the shortest dimension the rabbeted side to save material
    if(length <= width)
    {
        float _innerDimX = length - (2 * _thickness);
    }
    else
    {
        float _innerDimX = width = (2 * _thickness);
    }
    
    switch(lidStyle)
    {
        default: _innerDimY = depth - _thickness;
            
        case 1: _innerDimY = depth - (2 * _thickness);
    }
    
    
    //rabbitInternalInstance.addToWork(rabbitInternalInstance.poly({0,0,width,depth}));
                                     
    
    
    
    return _content;
}