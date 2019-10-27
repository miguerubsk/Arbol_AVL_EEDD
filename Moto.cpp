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

Moto& Moto::operator=(const Moto &orig) {
        if (this!=&orig){
            id=orig.id;            
            posicion=orig.posicion;
            usadoPor=orig.usadoPor;          
        }
        return *this;
}

bool Moto::operator<(const Moto &orig){
        return id<orig.id;
}

bool Moto::operator==(const Moto &orig) {  //para ordenar las motos
        return id==orig.id;
}

bool Moto::seActiva(Cliente *cli){
    estado=ACTIVA;
    usadoPor=cli;
}

void Moto::seDesactiva(){
    estado=BLOQUEADA;
    usadoPor=0;
}