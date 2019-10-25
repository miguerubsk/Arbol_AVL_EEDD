/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EcoCityMoto.h
 * Author: Miguel González García y Fernando Jiménez Quesada
 *
 * Created on October 24, 2019, 12:07 PM
 */

#ifndef ECOCITYMOTO_H
#define ECOCITYMOTO_H

#include "Cliente.h"
#include "vectordinamico.h"
#include "AVL.h"
#include <fstream>
#include <sstream>



class EcoCityMoto {
public:
    EcoCityMoto();
    EcoCityMoto(const EcoCityMoto& orig);
    virtual ~EcoCityMoto();
    void cargarClientes(std::string filename);
    void cargarMotos(std::string filename);
    AVL<Cliente>* GetAVL() {
        return &clientes;
    }
        vectordinamico<Moto>* Getvectordinamico() {
        return &motos;
    }

private:
    unsigned int idUltimo;
    vectordinamico<Moto> motos;
    AVL<Cliente> clientes;

};

#endif /* ECOCITYMOTO_H */

