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
#include <ctime>


#define ENABLE_COLLISION 1
#define ENABLE_RELATIVE_GRAVITY 1
#define ENABLE_GRAVITY 0

#define NUM_OF_BALLS 5
#define X_BOUNDARY 100
#define Y_BOUNDARY 100

#define RANDOM(X) rand() % (X * 100) / 100.0
#define RANDOM_N(X) (rand() % (X * 100) - X * 100 / 2) / 100.0



static Ball balllist[NUM_OF_BALLS];

void init_ball_list(void){
	/*
	for (int i = 0; i < NUM_OF_BALLS; i++) {
		balllist[i] = Ball(RANDOM(X_BOUNDARY), RANDOM(Y_BOUNDARY), 0, 0, 3, 100);
		
		if (ENABLE_GRAVITY) {
			balllist[i].ay(10);
		}
	}
	*/
	
	
	balllist[0] = Ball(50, 50, 0, 0, 3, 1400, false);
	balllist[1] = Ball(50, 20, 10, 0, 0.5, 1, false);
	balllist[2] = Ball(50, 10, 10, 0, 1, 20, false);
	balllist[3] = Ball(10, 50, 0, -10, 0.5, 5, false);
	balllist[4] = Ball(30, 60, -12, -12, 1, 10, false);
	/*
	balllist[0] = Ball(30, 50, 0, -15, 1, 50);
	balllist[1] = Ball(70, 50, 0, 15, 1, 50);
	balllist[2] = Ball(50, 50, 0, 0, 2, 500);
	*/
	
}

void simulation(void){
	
	for (int i = 0; i < NUM_OF_BALLS; i++) {
		balllist[i].collide_with_boundary(0, X_BOUNDARY, 0, Y_BOUNDARY);
		for (int j = i + 1; j < NUM_OF_BALLS; j++) {
			if (ENABLE_COLLISION) {
				balllist[i].collide_with_ball(balllist[j]);
			}
			
		}
		if (ENABLE_RELATIVE_GRAVITY) {
			balllist[i].gravity_with_ball(balllist, i, NUM_OF_BALLS);
		}
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

	printFPS(0, 0.98 * Y_BOUNDARY);
	
	
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
	glOrtho(0, X_BOUNDARY, 0, Y_BOUNDARY, -1, 1);
	
	glLineWidth(1.0f);//default line width =1
	
	init_ball_list();
}


int main(int argc,char **argv)
{
	srand(time(0));
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