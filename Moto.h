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
struct Estado{
    std::string estado;
    Estado():estado("bloqueada"){}
    Estado(std::string _estado): estado(_estado){}
};

class Moto {
public:
    Moto();
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
    Estado estatus;
};

#endif /* MOTO_H */

