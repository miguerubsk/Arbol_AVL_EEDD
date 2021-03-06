/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moto.cpp
 * Author: Fernando Jiménez Quesada y Miguel González García
 * 
 * Created on October 24, 2019, 12:07 PM
 */

#include "Moto.h"
/**
 * @brief constructor por defecto de moto
 **/
Moto::Moto(): id(""), posicion(0, 0), estado(BLOQUEADA), usadoPor(0) {
}

void Moto::setEstado(Status estado) {
    this->estado = estado;
}

Status Moto::getEstado() const {
    return estado;
}

void Moto::setUsadoPor(Cliente* usadoPor) {
    this->usadoPor = usadoPor;
}

Cliente* Moto::getUsadoPor() const {
    return usadoPor;
}

void Moto::setPosicion(UTM posicion) {
    this->posicion = posicion;
}

void Moto::setId(std::string id) {
    this->id = id;
}
/**
 * @brief constructor copia de moto
 * @param A es la moto de la cual queremos hacer la copia
 **/
Moto::Moto(const Moto& orig): id(orig.id), usadoPor(orig.usadoPor), estado(orig.estado), posicion(orig.posicion) {
}
/**
 * @brief destructor correpondiente de moto
 **/
Moto::~Moto() {
}
/**
 * @brief funcion get de la posicion
 * @return devuelve la posicion de la moto
 **/
UTM& Moto::getPosicion(){
    return posicion;
}
/**
 * @brief funcion get de id
 * @return devuelve el id de la moto
 **/
std::string Moto::getId() const {
    return id;
}
/**
 * @brief funcion get del estado
 * @return devuelve el estado de la moto
 **/
Status& Moto::getStatus() {
    return estado;
}
/**
 * @brief funcion del operador igual para la clase moto
 * @param A es la moto la cual queremos igualar
 * @return devuelve la moto del resultado de hacer el igual
 **/
Moto& Moto::operator=(const Moto &orig) {
        if (this!=&orig){
            id=orig.id;            
            posicion=orig.posicion;
            usadoPor=orig.usadoPor;          
        }
        return *this;
}
/**
 * @brief funcion del operador menor para la clase moto
 * @param A es la moto la cual queremos comparar
 * @return devuelve TRUE o FALSE dependiendo si es menor o mayor
 **/
bool Moto::operator<(const Moto &orig){
        return id<orig.id;
}
/**
 * @brief funcion del operador de comparacion para ordenar las motos
 * @param A es la moto la cual queremos comparar
 * @return devuelve TRUE o FALSE dependiendo si es la misma o no
 **/
bool Moto::operator==(const Moto &orig) {  //para ordenar las motos
        return id==orig.id;
}
/**
 * @brief funcion para activar la moto de un cliente
 * @param A es el cliente que vamos a usar para activarle la moto en cuestion
 **/
bool Moto::seActiva(Cliente *cli){
    estado=ACTIVA;
    usadoPor=cli;
}
/**
 * @brief funcion para desactivar la moto de un cliente
 **/
void Moto::seDesactiva(){
    estado=BLOQUEADA;
    usadoPor=0;
}