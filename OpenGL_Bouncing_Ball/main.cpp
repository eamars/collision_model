//
//  main.cpp
//  OpenGL_Bouncing_Ball
//
//  Created by Ran Bao on 30/09/14.
//  Copyright (c) 2014 R&B. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <GLUT/GLUT.h>
#include <cmath>
#include "fps.h"
#include "GLColor.h"
#include "TextBox.h"
#include "ball.h"

#define RANDOM(X) rand() % (X * 100) / 100.0
#define RANDOM_N(X) (rand() % (X * 100) - X * 100 / 2) / 100.0
#define NUM_OF_BALLS 20

const float x_boundary = 10;
const float y_boundary = 10;



static Ball balllist[NUM_OF_BALLS];

void init_ball_list(void){
	for (int i = 0; i < NUM_OF_BALLS; i++) {
		balllist[i] = Ball(RANDOM(10), RANDOM(10), RANDOM_N(10), RANDOM_N(10), 0.2);
		balllist[i].ay(G);
	}
}

void simulation(void){
	
	for (int i = 0; i < NUM_OF_BALLS; i++) {
		balllist[i].collide_with_boundary(0, 10, 0, 10);
	}
	
	for (int i = 0; i < NUM_OF_BALLS; i++) {
		for (int j = i + 1; j < NUM_OF_BALLS; j++) {
			balllist[i].collide_with_ball(balllist[j]);
		}
	}
	
	for (int i = 0; i < NUM_OF_BALLS; i++) {
		balllist[i].advance();
	}
	
}

void draw(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	
	
	// draw balls
	for (int i = 0; i < NUM_OF_BALLS; i++) {
		balllist[i].draw();
	}
	

	
	
	glFlush();

	printFPS(0, 9.8);
	
	
	glutSwapBuffers();
}

void idle(void){
	simulation();
	draw();
}

void init(void)
{
	/* clearing background */
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, x_boundary, 0, y_boundary, -1, 1);
	
	glLineWidth(1.0f);//default line width =1
	
	init_ball_list();
}


int main(int argc,char **argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Bouncing Ball");
	init();
	glutDisplayFunc(simulation);
	glutIdleFunc(idle);
	glutMainLoop();
	
	return 0;
}