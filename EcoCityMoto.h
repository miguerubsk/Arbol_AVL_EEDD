/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EcoCityMoto.h
 * Author: Fernando
 *
 * Created on October 22, 2019, 5:01 PM
 */

#ifndef ECOCITYMOTO_H
#define ECOCITYMOTO_H

#include "AVL.h"
#include "vectordinamico.h"
#include "Cliente.h"
#include "Moto.h"

class EcoCityMoto {
public:
    EcoCityMoto();
    EcoCityMoto(const EcoCityMoto& orig);
    virtual ~EcoCityMoto();
    //IMPLEMENTAR
    Moto localizaMotoCercana(UTM ubicacion);
    //IMPLEMENTAR
    void desbloqueaMoto(Moto m, Cliente c);
private:
    unsigned idUltimo;
    AVL<Cliente> avlClientes;
    vectordinamico<Moto> v;
};

#endif /* ECOCITYMOTO_H */

