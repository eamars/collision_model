//
//  TextBox.cpp
//  OpenGL_Timer_CPP
//
//  Created by Ran Bao on 4/27/13.
//  Copyright (c) 2013 Ran Bao. All rights reserved.
//

#include "TextBox.h"

TextBox::TextBox(){
	
	x_axis = y_axis = 0;
	font = NULL;
	
	data = new char[1];
	len = 0;
	data[0] = 0;
}

TextBox::TextBox(float x, float y, const char *p, const float *fontColor, void *f){
	for (int i = 0; i < 3; i++) {
		color[i] = fontColor[i];
	}
	
	x_axis = x;
	y_axis = y;
	
	len = strlen(p);
	data = new char[len + 1];
	strcpy(data, p);
	
	font = f;
	
}

TextBox::TextBox(float x, float y, const std::string &ref, const float *fontColor, void *f){
	
	for (int i = 0; i < 3; i++) {
		color[i] = fontColor[i];
	}
	
	x_axis = x;
	y_axis = y;
	
	len = ref.length();
	data = new char[len + 1];
	strcpy(data, ref.c_str());
	
	font = f;
}

TextBox::~TextBox(){
	delete [] data;
}

void TextBox::diag_info(){
	std::cout << "String: " << data << std::endl;
	std::cout << "X: " << x_axis << "  Y: " << y_axis << std::endl;
	std::cout << "R: " << color[0] << "  G: " << color[1] << "  B: " << color[2] << std::endl;
	std::cout << "Font: " << font << std::endl;
	
}

void TextBox::draw(){
	
	glPushMatrix();
	glColor3fv(color);
	glRasterPos2f(x_axis, y_axis);

	for (size_t i = 0; i < len; i++) {
		glutBitmapCharacter(font, data[i]);
	}
	glFlush();
	glPopMatrix();
	
	
}

NewTextBox::NewTextBox(){
	x_axis = y_axis = 0;
	font = NULL;
	
}

NewTextBox::NewTextBox(float x, float y, const float *fontColor, void *f){
	for (int i = 0; i < 3; i++) {
		color[i] = fontColor[i];
	}
	x_axis = x;
	y_axis = y;
	font = f;

}

NewTextBox::~NewTextBox(){
	
}

void NewTextBox::update(const std::string &text_to_display){
	text = text_to_display;
}

void NewTextBox::draw(){
	
	glPushMatrix();
	glColor3fv(color);
	glRasterPos2f(x_axis, y_axis);
	
	for (std::string::iterator it=text.begin(); it != text.end(); it++) {
		glutBitmapCharacter(font, *it);
	}
	glFlush();
	glPopMatrix();
	
	
}

void NewTextBox::diag_info(){
	std::cout << "String: " << text << std::endl;
	std::cout << "X: " << x_axis << "  Y: " << y_axis << std::endl;
	std::cout << "R: " << color[0] << "  G: " << color[1] << "  B: " << color[2] << std::endl;
	std::cout << "Font: " << font << std::endl;
	
}
