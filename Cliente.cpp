/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: Fernando
 *
 * Created on October 27, 2019, 11:14 PM
 */

#include "Cliente.h"


        void Cliente::desbloquearMoto(Moto *m){
            acceso->desbloqueaMoto(m,this);
        }
//        //TODO
        void Cliente::terminarTrayecto(){
            //ListaDEnlazada<Itinerario>::Iterador i=rutas.iteradorFinal();
            
        }
//        //IMPLEMENTAR
        Moto * Cliente::buscarMotoCercana(){
            Moto* m=acceso->LocalizaMotoCercana(posicion);
            return m;
        }
        
        ostream& operator<<(ostream & os, const Cliente & obj)
        {
	return os << "DNI: " << obj.GetDNI() << " | " << "Nombre: " << obj.GetNOMBRE() << " | " << "Direccion: " << obj.GetDIRECCION() << " Id del ultimo " << obj.acceso->getIdUltimo()<< " | " << "\n";
        }