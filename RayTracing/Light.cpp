//
//  Light.cpp
//  RayTracing
//
//  Created by Iago Chaves on 02/04/14.
//  Copyright (c) 2014 Iago Chaves. All rights reserved.
//

#include "Light.h"

Light::Light(vec::fixed<3> position, vec::fixed<3> ld, vec::fixed<3> ls, vec::fixed<3> la) {
    this->position = position;
    this->ld = ld;
    this->ls = ls;
    this->la = la;
}

vec Light::getDiffuseLight() {
    return this->ld;
}

vec Light::getSpecularLight() {
    return this->ls;
}

vec Light::getAmbientLight() {
    return this->la;
}