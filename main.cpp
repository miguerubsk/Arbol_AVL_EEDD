/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Fernando Jiménez Quesada y Miguel González García
 *
 * Created on 19 de septiembre de 2019, 13:07
 */
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <math.h>
#include <ctime>
#include "vectordinamico.h"
#include "ListaDEnlazada.h"
#include "Cliente.h"
#include "AVL.h"


using namespace std;

double calculardistaciamaslejana(vectordinamico<Cliente> v) {
    double distancia, maxDistancia = 0;
    for (int i = 0; i < v.tam() - 1; i++) {
        for (int j = i + 1; j < v.tam(); j++) {
            distancia = v[i].distancia(v[j]);

            if (distancia > maxDistancia)
                maxDistancia = distancia;
        }
    }
    return maxDistancia;
}

void MaxMinLatLon(vectordinamico<Cliente> v, double &maxLon, double &maxLat, double &minLon, double &minLat){
       maxLon=-9999999, maxLat=-9999999, minLon=9999999, minLat=9999999;
       for (int i=0; i<v.tam(); i++){
           double x=v[i].GetUTM().GetLongitud();
           if (x>maxLon)
               maxLon=x;
           else
               if (x<minLon)
                   minLon=x;
           x=v[i].GetUTM().GetLatitud();
           if (x>maxLat)
               maxLat=x;
           else
               if (x<minLat)
                   minLat=x;

       }
}

int main(int argc, char** argv) {
    try {
        EcoCityMoto prueba;
        //RECORRE EN INORDEN
        prueba.getCliente().recorreInorden();
        //ALTURA DEL AVL
        std::cout << "La altura del avl de los clientes es: " << prueba.getCliente().altura() << std::endl;
        //NUMERO DE CLIENTES DEL AVL
        std::cout << "El numero de clientes del avl es: " << prueba.getCliente().numElementos() << std::endl;
        Cliente buscar, resultado;
        buscar.SetDni("24242105C");
        //BUSCAR CLIENTE CON DNI 67839521O
        resultado = prueba.buscarCliente("67839521O");
        std::cout << "Cliente encontrado: " << std::endl;
        std::cout << "DNI: " << resultado.GetDNI() << std::endl;
        std::cout << "Nombre: " << resultado.GetNOMBRE() << std::endl;
        //DESBLOQUEAR MOTO
        resultado.desbloquearMoto(resultado.buscarMotoCercana());
        std::cout << "Se desbloquea la moto " << resultado.getItinerario().iteradorFinal().getdatoaux()->GetVehiculos()->GetId() << std::endl;

        UTM max(37, 3), min(38, 4);
        std::mt19937 rnd(std::time(NULL));
        std::uniform_real_distribution<> latitud(min.GetLatitud(), max.GetLatitud());
        std::uniform_real_distribution<> longitud(min.GetLongitud(), max.GetLongitud());
        UTM fin(latitud(rnd), longitud(rnd));

        resultado.SetPosicion(fin);
        //TERMINAR EL TRAYECTO
        resultado.terminarTrayecto();

        std::cout << "TERMINADO ITINERARIO" << std::endl;
        std::cout << "Id:" << resultado.getItinerario().iteradorFinal().getdatoaux()->GetId() << std::endl;
        std::cout << "UTM inicio:" << resultado.getItinerario().iteradorFinal().getdatoaux()->GetInicio().GetLatitud() << "<-->" << resultado.getItinerario().iteradorFinal().getDato().GetInicio().GetLongitud() << std::endl;
        std::cout << "UTM fin:" << resultado.getItinerario().iteradorFinal().getdatoaux()->GetFin().GetLatitud() << "<-->" << resultado.getItinerario().iteradorFinal().getDato().GetFin().GetLongitud() << std::endl;
        std::cout << "Fecha:" << resultado.getItinerario().iteradorFinal().getdatoaux()->GetFecha() << std::endl;
        std::cout << "Duracion:" << resultado.getItinerario().iteradorFinal().getdatoaux()->GetMinutos() << std::endl;
        std::cout << "Id de la moto:" << resultado.getItinerario().iteradorFinal().getdatoaux()->GetVehiculos()->GetId() << std::endl;





    } catch (std::string &e) {
        cout << e << endl;
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}