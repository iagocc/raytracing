//
//  main.cpp
//  RayTracing
//
//  Created by Iago Chaves on 11/03/14.
//  Copyright (c) 2014 Iago Chaves. All rights reserved.
//

#include <iostream>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "/usr/include/armadillo"
#include "Scenario.h"
#include "Light.h"

using namespace arma;
using namespace std;

rgb scene[WIDTH][HEIGHT];

void renderScene(void) {
    
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            
            rgb color = scene[i][j];
            glBegin(GL_POINTS);
                glColor3f(color.r, color.g, color.b);
                glVertex2f(i,j);
            glEnd();
            
            
        }
    }
    
    glFinish();
    glutSwapBuffers();
}

int main(int argc, char * argv[]) {
    
    vec observer = {0,0,0};
    Scenario *scenario = new Scenario();
    scenario->setUpViewer(observer);
    
    vec::fixed<3> ld = {.7,.7,.7};
    vec::fixed<3> ls = {1,1,1};
    vec::fixed<3> la = {.2,.2,.2};
    vec::fixed<3> light_position = {20, 20, 0};
    Light *light1 = new Light(light_position, ld,ls,la);
    scenario->addLight(light1);
    
    vec obj1_center = {0,0,30};
    Sphere *obj1 = new Sphere(obj1_center, 5);
    vec kd = {1, .5, 0};
    vec ks = {1, 1, 1};
    vec ka = {1, 1, 1};
    obj1->setMaterial(100, kd, ks, ka);
    scenario->addObject(obj1);
    
    vec obj2_center = {10,10,50};
    Sphere *obj2 = new Sphere(obj2_center, 3);
    obj2->setMaterial(32, kd, ks, ka);
    scenario->addObject(obj2);
    
    scenario->draw();
    memcpy(scene, scenario->scene, WIDTH*HEIGHT*sizeof(rgb));
    
//    stringstream ss;
//    for(int i = 0; i < WIDTH; i++) {
//        for(int j = 0; j < HEIGHT; j++) {
//            ss << scene[i][j].r << " ";
//        }
//        ss << endl;
//    }
//    ofstream myFile;
//    myFile.open("/Users/iagocc/matrix.txt");
//    if(!myFile.fail()) {
//        myFile << "Matrix:\n";
//        myFile << ss.str();
//    }
//    myFile.close();
    
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("Ray Tracing");
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WIDTH, HEIGHT, 0.0, 1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    
    glutDisplayFunc(renderScene);
    glutMainLoop();
    
    return 1;
}

