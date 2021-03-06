//
//  GLColor.c
//  OpenGL_Timer_CPP
//
//  Created by Ran Bao on 4/27/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved
//

#include "GLColor.h"


namespace GLColor {
	const float GLMakeColor(int r, int b, int g){
		float RETURN_COLOR[3];
		RETURN_COLOR[0] = r;
		RETURN_COLOR[1] = b;
		RETURN_COLOR[2] = g;
		return *RETURN_COLOR;
	}
}