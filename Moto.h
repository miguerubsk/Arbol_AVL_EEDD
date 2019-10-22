/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Moto.h
 * Author: Fernando
 *
 * Created on October 22, 2019, 5:04 PM
 */

#ifndef MOTO_H
#define MOTO_H

#include <string>

#include "UTM.h"
#include "Cliente.h"


class Moto {
public:
    Moto();
    Moto(const Moto& orig);
    virtual ~Moto();
    //IMPLEMENTAR
    bool seActiva(Cliente cli);
    //IMPLEMENTAR
    void seDesactiva();
private:
    std::string id;
    UTM posicion;
    std::string Estado;
};

#endif /* MOTO_H */

