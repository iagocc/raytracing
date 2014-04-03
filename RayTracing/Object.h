//
//  Object.h
//  RayTracing
//
//  Created by Iago Chaves on 21/03/14.
//  Copyright (c) 2014 Iago Chaves. All rights reserved.
//

#ifndef __RayTracing__Object__
#define __RayTracing__Object__

#include <iostream>
#include "/usr/include/armadillo"

using namespace arma;
using namespace std;

struct rgb_str {
    double r = 0;
    double g = 0;
    double b = 0;
} typedef rgb;

class Object {
    
public:
    
    vec::fixed<3> kd;
    vec::fixed<3> ks;
    vec::fixed<3> ka;
    float alpha;
    
    virtual long double isIntercected(vec &observer, vec &direction) = 0;
    virtual void setMaterial(float alpha, vec kd, vec ks, vec ka) = 0;
    virtual vec getNormalFor(vec point) = 0;
    
};

#endif /* defined(__RayTracing__Object__) */
