//
//  Sphere.h
//  RayTracing
//
//  Created by Iago Chaves on 21/03/14.
//  Copyright (c) 2014 Iago Chaves. All rights reserved.
//

#ifndef __RayTracing__Sphere__
#define __RayTracing__Sphere__

#include <iostream>
#include "Object.h"

using namespace std;

class Sphere : public Object {
    
public:
    float radius;
    vec center;
    
    Sphere(vec &center, float radius);
    long double isIntercected(vec &observer, vec &direction);
    void setMaterial(float alpha, vec kd, vec ks, vec ka);
    vec getNormalFor(vec point);
};

#endif /* defined(__RayTracing__Sphere__) */
