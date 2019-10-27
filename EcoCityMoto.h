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
    Moto* LocalizaMotoCercana(UTM &ubicacion);
    void desbloqueaMoto(Moto *moto, Cliente *cli);
    unsigned int getIdUltimo() const {
        return idUltimo;
    }



private:
    unsigned int idUltimo;
    vectordinamico<Moto> motos;
    AVL<Cliente> clientes;

};

#endif /* ECOCITYMOTO_H */

