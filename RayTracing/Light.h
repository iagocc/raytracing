//
//  Light.h
//  RayTracing
//
//  Created by Iago Chaves on 02/04/14.
//  Copyright (c) 2014 Iago Chaves. All rights reserved.
//

#ifndef __RayTracing__Light__
#define __RayTracing__Light__

#include <iostream>
#include "/usr/include/armadillo"

using namespace arma;
using namespace std;

class Light {
    vec::fixed<3> ld;
    vec::fixed<3> ls;
    vec::fixed<3> la;
public:
    vec::fixed<3> position;
    
    Light(vec::fixed<3> postion, vec::fixed<3> ld, vec::fixed<3> ls, vec::fixed<3> la);
    vec getDiffuseLight();
    vec getSpecularLight();
    vec getAmbientLight();
};

#endif /* defined(__RayTracing__Light__) */
