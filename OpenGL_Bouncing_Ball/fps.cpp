//
//  fps.cpp
//  pendulum
//
//  Created by Ran Bao on 9/23/13.
//  Copyright (c) 2013 R&B. All rights reserved.
//

#include "fps.h"
#include "TextBox.h"

double CalFrequency()
{
    static int count;
    static double save;
    static clock_t last, current;
    double timegap;
    
    ++count;
    if( count <= 50 )
        return save;
    count = 0;
    last = current;
    current = clock();
    timegap = (current-last)/(double)CLOCKS_PER_SEC;
    save = 50.0/timegap;
    return save;
}

void printFPS(float x, float y){
	double fpsValue = CalFrequency();
	std::string fpsString = "FPS: " + std::to_string(fpsValue);
	
	
	TextBox fpsObject(x, y, fpsString, GLColor::GL_WHITE_COLOR, GLUT_BITMAP_HELVETICA_12);
	fpsObject.draw();
	
	
}