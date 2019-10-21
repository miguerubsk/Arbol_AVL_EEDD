/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Itinerario.h
 * Author: Miguerubsk
 *
 * Created on 5 de octubre de 2019, 11:33
 */

#ifndef ITINERARIO_H
#define ITINERARIO_H

#include "fecha.h"
#include <cstdlib>
#include "UTM.h"


class Itinerario {
public:
    Itinerario(int _id, UTM &_inicio, UTM &_fin, Fecha &_fecha, int _minutos);
    Itinerario(const Itinerario& orig);
    virtual ~Itinerario();
    Fecha GetFecha() const {
        return fecha;
    }

    void SetFecha(Fecha fecha) {
        this->fecha = fecha;
    }

    UTM GetFin() const {
        return fin;
    }

    void SetFin(UTM fin) {
        this->fin = fin;
    }

    int GetId() const {
        return id;
    }

    void SetId(int id) {
        this->id = id;
    }

    UTM GetInicio() const {
        return inicio;
    }

    void SetInicio(UTM inicio) {
        this->inicio = inicio;
    }

    int GetMinutos() const {
        return minutos;
    }

    void SetMinutos(int minutos) {
        this->minutos = minutos;
    }


private:
    
    int id, minutos;
    UTM inicio, fin;
    Fecha fecha;

};

#endif /* ITINERARIO_H */

