/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moto.cpp
 * Author: Fernando
 * 
 * Created on October 24, 2019, 12:07 PM
 */

#include "Moto.h"

Moto::Moto() {
}

Moto::Moto(const Moto& orig): id(orig.id), usadoPor(orig.usadoPor), estado(orig.estado), posicion(orig.posicion) {
}

Moto::~Moto() {
}

UTM Moto::getPosicion() const {
    return posicion;
}

std::string Moto::getId() const {
    return id;
}

Status Moto::getStatus() const {
    return estado;
}
