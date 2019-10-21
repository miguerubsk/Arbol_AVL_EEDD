/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: Miguerubsk
 *
 * Created on 23 de septiembre de 2019, 22:30
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include "UTM.h"
#include "random.h"
#include "fecha.h"
#include "Itinerario.h"
#include "ListaDEnlazada.h"

using namespace std;


class Cliente {
    
    private:
        string dni;
        string pass;
        string nombre;
        string direccion;
        ListaDEnlazada<Itinerario> itinerarios;
        UTM posicion;

    
    public:
        //Constructor

        Cliente() : dni("0"), pass("0"), nombre("0"), direccion("0"), posicion(0.0, 0.0) {
        }

        Cliente(string _dni, string _pass, string _nombre, string _direccion, double _latitud, double _longitud) :
        dni(_dni), pass(_pass), nombre(_nombre), direccion(_direccion), posicion(_latitud, _longitud) {
        }

        string GetDNI() const {
            return dni;
        }

        string GetNOMBRE() const {
            return nombre;
        }

        UTM GetUTM() const {
            return posicion;
        }

        bool operator==(const Cliente& orig) {
            std::size_t found = this->nombre.find(orig.nombre);

            if (found != std::string::npos)
                return true;

            return false;
        }

        bool operator<(Cliente& right) const {
            return (nombre < right.nombre);
        }

        bool operator>(Cliente& right) const {
            return (nombre > right.nombre);
        }

        void SetDireccion(string direccion) {
            this->direccion = direccion;
        }

        void SetDni(string dni) {
            this->dni = dni;
        }

        void SetNombre(string nombre) {
            this->nombre = nombre;
        }

        void SetPass(string pass) {
            this->pass = pass;
        }

        void SetPosicion(UTM posicion) {
            this->posicion = posicion;
        }

        Cliente& operator=(const Cliente &orig) {
            dni = orig.dni;
            nombre = orig.nombre;
            direccion = orig.direccion;
            pass = orig.pass;
            posicion = orig.posicion;
            return *this;
        }

        double distancia(const Cliente &cli) {
            return sqrt(pow((cli.posicion.GetLatitud()-this->posicion.GetLatitud()),2)+pow((cli.posicion.GetLongitud()-this->posicion.GetLongitud()),2));
        }

        void crearItinerarios(int num, int IdUltimo, const UTM &min, const UTM &max){
            Set_random(rand());
            for (int i=0; i<num; i++){
                Fecha f(rand()%28+1,rand()%12+1,rand()%10+2019);
                UTM inicio( Randfloat(min.GetLatitud(),max.GetLatitud()),
                            Randfloat(min.GetLongitud(),max.GetLongitud()));
                UTM fin( Randfloat(min.GetLatitud(),max.GetLatitud()),
                            Randfloat(min.GetLongitud(),max.GetLongitud()));
                int minutos = rand()%100;
                Itinerario viaje(++IdUltimo,inicio,fin,f,minutos);
                itinerarios.insertarFinal(viaje);
            }
        }



};

#endif /* CLIENTE_H */