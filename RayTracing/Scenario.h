//
//  Scenario.h
//  RayTracing
//
//  Created by Iago Chaves on 11/03/14.
//  Copyright (c) 2014 Iago Chaves. All rights reserved.
//

#ifndef __RayTracing__Scenario__
#define __RayTracing__Scenario__

#include <iostream>
#include "/usr/include/armadillo"

#include "Object.h"
#include "Sphere.h"
#include "Light.h"

#define WIDTH 600
#define HEIGHT 600

using namespace arma;
using namespace std;

class Scenario {

    vec observer;
    vector<Object*> objects;
    vector<Light*> lights;
    
public:
    rgb scene[WIDTH][HEIGHT];
    
    Scenario();
    void draw();
    rgb rayTracing(float x, float y);
    rgb getColorOf(vec &point, Object *object);
    void setUpViewer(vec &observer);
    
    void addObject(Object *o);
    
    vector<Light*> getLights();
    void addLight(Light *light);
    
    vec getObserver();
    
};



#endif /* defined(__RayTracing__Scenario__) */
