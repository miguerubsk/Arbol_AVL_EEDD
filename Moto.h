/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moto.h
 * Author: Fernando
 *
 * Created on October 24, 2019, 12:07 PM
 */

#ifndef MOTO_H
#define MOTO_H

#include <string>
#include "UTM.h"
//#include "Cliente.h"
class Cliente;

enum Status {BLOQUEADA,ACTIVA,SINBATERIA,ROTA};


class Moto {
public:
    Moto();
    Moto(std::string _id, double _latitud, double _longitud, int _estado) :
        id(_id), posicion(_latitud, _longitud) {
        switch(_estado){
            case 0: estado = BLOQUEADA;
            case 1: estado = ACTIVA;
            case 2: estado = SINBATERIA;
            case 3: estado = ROTA;
        }
    }
    UTM getPosicion() const;
    std::string getId() const;
    Status getStatus() const;
    Moto(const Moto& orig);
    virtual ~Moto();
private:
    std::string id;
    UTM posicion;
    Cliente *usadoPor;
    Status estado;
};

#endif /* MOTO_H */

