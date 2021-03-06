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
        cout << "La altura del avl de los clientes es: " << prueba.getCliente().altura() << endl;
        //NUMERO DE CLIENTES DEL AVL
        cout << "El numero de clientes del avl es: " << prueba.getCliente().numElementos() << endl;
        Cliente cliente1, *buscado;
        cliente1.SetDni("24242105C");
        //BUSCAR CLIENTE CON DNI 67839521O
        buscado = prueba.buscarCliente("67839521O");
        cout << "Cliente encontrado: " << endl;
        cout << "DNI: " << buscado->GetDNI() << endl;
        cout << "Nombre: " << buscado->GetNOMBRE() << endl;
        //DESBLOQUEAR MOTO
        buscado->desbloquearMoto(buscado->buscarMotoCercana());
        cout << "Se desbloquea la moto " << buscado->getItinerario().iteradorFinal().getdatoaux()->GetVehiculos()->GetId() << endl;

        UTM max(37, 3), min(38, 4);
        mt19937 rnd(time(NULL));
        uniform_real_distribution<> latitud(min.GetLatitud(), max.GetLatitud());
        uniform_real_distribution<> longitud(min.GetLongitud(), max.GetLongitud());
        UTM fin(latitud(rnd), longitud(rnd));

        buscado->SetPosicion(fin);
        //TERMINAR EL TRAYECTO
        buscado->terminarTrayecto();
        cout << "TERMINADO ITINERARIO" << endl;
        cout << "Id:" << buscado->getItinerario().iteradorFinal().getdatoaux()->GetId() << endl;
        cout << "UTM inicio:" << buscado->getItinerario().iteradorFinal().getdatoaux()->GetInicio().GetLatitud() << "<-->" << buscado->getItinerario().iteradorFinal().getDato().GetInicio().GetLongitud() << endl;
        cout << "UTM fin:" << buscado->getItinerario().iteradorFinal().getdatoaux()->GetFin().GetLatitud() << "<-->" << buscado->getItinerario().iteradorFinal().getDato().GetFin().GetLongitud() << endl;
        cout << "Fecha:" << buscado->getItinerario().iteradorFinal().getdatoaux()->GetFecha() << endl;
        cout << "Duracion:" << buscado->getItinerario().iteradorFinal().getdatoaux()->GetMinutos() << endl;
        cout << "Id de la moto:" << buscado->getItinerario().iteradorFinal().getdatoaux()->GetVehiculos()->GetId() << endl;
    } catch (std::string &e) {
        cout << e << endl;
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}