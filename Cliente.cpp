/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: Fernando Jiménez Quesada y Miguel González García
 *
 * Created on October 27, 2019, 11:14 PM
 */

#include "Cliente.h"
/**
     * @brief funcion para desbloquear la moto que esta asociada a cliente
     * @param A es la moto en cuestion que queremos desbloquear
**/
void Cliente::desbloquearMoto(Moto *m) {
    acceso->desbloqueaMoto(m, this);
}


void Cliente::terminarTrayecto() {
    //ListaDEnlazada<Itinerario>::Iterador i=rutas.iteradorFinal();

}
/**
     * @brief funcion para buscar la moto mas cercana al cliente en cuestion
     * @return devuelve la moto la cual es la mas cercana del cliente(this)
**/
Moto * Cliente::buscarMotoCercana() {
    Moto* m = acceso->LocalizaMotoCercana(posicion);
    return m;
}
//OPERADOR << PARA CLIENTE
ostream& operator<<(ostream & os, const Cliente & obj) {
    return os << "DNI: " << obj.GetDNI() << " | " << "Nombre: " << obj.GetNOMBRE() << " | " << "Direccion: " << obj.GetDIRECCION() << " Id del ultimo " << obj.acceso->getIdUltimo() << " | " << "\n";
}