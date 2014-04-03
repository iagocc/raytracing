//
//  Sphere.cpp
//  RayTracing
//
//  Created by Iago Chaves on 21/03/14.
//  Copyright (c) 2014 Iago Chaves. All rights reserved.
//

#include "Sphere.h"

Sphere::Sphere(vec &center, float radius) {
    this->center = center;
    this->radius = radius;
}

long double Sphere::isIntercected(vec &observer, vec &direction) {

    vec to_observer_vector = (center - observer);
    long double A = dot(direction, direction);
    long double B = 2*(dot(direction, to_observer_vector));
    long double C = dot(to_observer_vector, to_observer_vector) - pow(radius, 2);
    
    long double delta = B*B - 4*A*C;
    
    if (delta < 0) {
        return -1;
    }
    
    long double t_p = (B + sqrt(delta))/( 2*A );
    long double t_s = (B - sqrt(delta))/( 2*A );
    
    long double t = (t_s > 1) ? t_s : t_p ;
    
    if (t >= 1) {
        return t;
    }
    
    return -1;
    
}

void Sphere::setMaterial(float alpha, vec kd, vec ks, vec ka) {
    this->alpha = alpha;
    this->kd = kd;
    this->ks = ks;
    this->ka = ka;
}

vec Sphere::getNormalFor(vec point) {
    return normalise(point - this->center);
}