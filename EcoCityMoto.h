/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EcoCityMoto.h
 * Author: Fernando
 *
 * Created on October 24, 2019, 12:07 PM
 */

#ifndef ECOCITYMOTO_H
#define ECOCITYMOTO_H

#include "vectordinamico.h"
#include "Moto.h"
#include "AVL.h"
#include <fstream>
#include <sstream>
#include "Cliente.h"

class Moto;

class EcoCityMoto {
public:
    EcoCityMoto();
    EcoCityMoto(const EcoCityMoto& orig);
    virtual ~EcoCityMoto();
    void cargarClientes(std::string filename);
    void cargarMotos(std::string filename);
    AVL<Cliente> getClientes() const {
        return clientes;
    }

    unsigned int getIdUltimo() const {
        return idUltimo;
    }

    void setIdUltimo(unsigned int idUltimo) {
        this->idUltimo = idUltimo;
    }

    vectordinamico<Moto> getMotos() const {
        return motos;
    }


private:
    unsigned int idUltimo;
    vectordinamico<Moto> motos;
    AVL<Cliente> clientes;

};

#endif /* ECOCITYMOTO_H */

