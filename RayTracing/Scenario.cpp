//
//  Scenario.cpp
//  RayTracing
//
//  Created by Iago Chaves on 11/03/14.
//  Copyright (c) 2014 Iago Chaves. All rights reserved.
//

#include "Scenario.h"

Scenario::Scenario() {
}

rgb Scenario::rayTracing(float screen_x, float screen_y) {
    
    /* Ponto sobre a matriz */
    vec o = {screen_x, screen_y, 1};
    /* Vetor direção  */
    vec d = normalise(o - this->observer);
//    vec d = {0,0,1};
    /* Ponto interceptado */
    vec x;
    /* Padrão da cor */
    rgb black;
    
    /* Iniciando o min_t como infinito */
    long double min_t = 99999999;
    /* Objeto mais próximo do observador */
    Object *nearest_obj = NULL;
    
    /* Percorre todos os objetos */
    for(vector<Object*>::iterator object = this->objects.begin(); object != this->objects.end(); ++object) {
        long double t = (*object)->isIntercected(o, d);
        
        if (t < min_t && t > 1) {
            min_t = t;
            nearest_obj = *object;
        }
        
    }
    
    if (nearest_obj != NULL) {
        /* Ponto sobre o objeto */
        vec::fixed<3> point = o + d*min_t;
        /* Phong */
        return this->getColorOf(point, nearest_obj);
    }
    
    return black;
}

rgb Scenario::getColorOf(vec &point, Object *object) {
    rgb color;
    
    /* Vetor que aponta para o observador */
    vec::fixed<3> v = normalise(this->getObserver() - point);
    /* Normal ao ponto na face */
    vec::fixed<3> n = object->getNormalFor(point);
    
    /* Percorre todas as luzes da cena */
    for(Light *light : this->getLights()) {
        
        /* Vetor que aponta para luz */
        vec::fixed<3> l = normalise(light->position - point);
        /* Vetor gerado pela reflexão */
        vec::fixed<3> r = normalise(2*(dot(l, n))*n - l);
        
        long double dot_ln = max(dot(l,n), 0.0);
        long double dot_rv = pow(max(dot(r, v), 0.0), object->alpha);
        
        /* I = Kd*Ld*max(dot(l,n)) + Ks*Ls*max(dot(r,v)^alpha, 0) + Ka*La */
  
        /* Operador % multiplica elemento por elemento */
        vec Ia = light->getAmbientLight() % object->ka;
        vec Id = (light->getDiffuseLight() % object->kd)*dot_ln;
        vec Is = (light->getSpecularLight() % object->ks)*dot_rv;
        
        vec I = Ia + Id + Is;
        
        color.r += min(I(0), 1.0);
        color.g += min(I(1), 1.0);
        color.b += min(I(2), 1.0);
        
    }
    
    return color;
}

void Scenario::draw() {
    
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            
            /* Colocar as coordenadas de -1 até 1, para evitar um grande angulo de abertura no frustum */
            double x = ((2*i)/(double)WIDTH) - 1;
            double y = ((2*j)/(double)HEIGHT) - 1;
            rgb c = rayTracing(x,y);
            this->scene[i][j] = c;
            
        }
    }
    
}

void Scenario::setUpViewer(vec &observer) {
    this->observer = observer;
}

void Scenario::addObject(Object *o) {
    this->objects.push_back(o);
}

vector<Light*> Scenario::getLights() {
    return this->lights;
}

void Scenario::addLight(Light *light) {
    this->lights.push_back(light);
}

vec Scenario::getObserver() {
    return this->observer;
}