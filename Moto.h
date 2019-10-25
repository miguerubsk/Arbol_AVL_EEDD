/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moto.h
 * Author: Miguel González García y Fernando Jiménez Quesada
 *
 * Created on October 24, 2019, 12:07 PM
 */

#ifndef MOTO_H
#define MOTO_H

#include "UTM.h"
//#include "Cliente.h"
class Cliente;

enum Status {bloqueada, activa, sinbateria, rota};

class Moto {
public:
    Moto();
    Moto(std::string _id, double _latitud, double _longitud, int _estado) :
        id(_id), posicion(_latitud, _longitud) {
        switch(_estado){
            case 0: estado = bloqueada;
            case 1: estado = activa;
            case 2: estado = sinbateria;
            case 3: estado = rota;
        }
    }
    Moto(const Moto& orig);
    virtual ~Moto();
    bool operator<(Moto& right) const {
        return (id < right.id);
    }

    bool operator>(Moto& right) const {
        return (id > right.id);
    }
    
private:
    std::string id;
    UTM posicion;
    Cliente *usadoPor;
    Status estado;
};

#endif /* MOTO_H */

