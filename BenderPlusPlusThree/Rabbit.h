//
//  Rabbit.h
//  BenderPlusPlusThree
//
//  Created by Ben Lewson on 11/5/16.
//  Copyright © 2016 Ben Lewson. All rights reserved.
//

#ifndef Rabbit_h
#define Rabbit_h

#include <iostream>
#include "SvgPacker.h"//Required for operation

class Rabbit
{
public:
    //Constructor
    Rabbit(float thickness);
    
    //Generate rabbit jointed box from dimensions and lid style
    //[0 = no lid, 1 = lid, 2 = hinged lid (future)]
    string generate(float length, float width, float depth, int lidStyle = 0);
    
private:
    float   _thickness;
    
    float   _length;
    float   _width;
    float   _depth;
    
    int     _lidStyle;
    
    float   _innerDimX;
    float   _innerDimY;
    
    string  _content;
    
};


#endif /* Rabbit_h */
