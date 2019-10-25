/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Fernando
 *
 * Created on 19 de septiembre de 2019, 13:07
 */
//#include "Cliente.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include "EcoCityMoto.h"


using namespace std;

class Cliente;

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

void leeClientes(string fileNameClientes, vectordinamico<Cliente> &v) {
    ifstream fe; //Flujo de entrada
    string linea; //Cada linea tiene un clienete
    int total = 0; //Contador de lineas o clientes

    //Variables auxiliares para almacenar los valores leidos
    string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon;



    //Asociamos el flujo al fichero 
    fe.open(fileNameClientes);

    if (fe.good()) {
        //Mientras no se haya llegado al final del fichero
        while (!fe.eof()) {
            getline(fe, linea); //Toma una linea del fichero
            stringstream ss; //Stream que trabaja sobre buffer interno         

            if (linea != "") {
                ++total;
            }

            if (total > 1) {
                //Inicializamos el contenido de ss
                ss << linea;

                //Leemos el NIF
                getline(ss, dni, ';'); //El caracter ; se lee y se elimina de ss

                //Leemos el pass
                getline(ss, pass, ';'); //El carater ; se lee y se elimina de ss

                //Leemos el nombre
                getline(ss, nombre, ';'); //El carater ; se lee y se elimina de ss

                //Leemos la direcciÃ³n
                getline(ss, direccion, ';'); //El carater ; se lee y se elimina de ss

                //Leemos la latitud y longitud
                getline(ss, latitud, ';'); //El carater ; se lee y se elimina de ss
                getline(ss, longitud, ';'); //El carater ; se lee y se elimina de ss

                dlat = stod(latitud);
                dlon = stod(longitud);

                //con todos los atributos leidos, se crea el cliente
                //                cout<<dni<<endl;
                Cliente client(dni, pass, nombre, direccion, dlat, dlon);
                v.insertar(client);
                if (total % 100 == 0) {
                    cout << "Leido cliente " << total << "\n  ";
                }
            }
        }

        cout << "Total de clientes en el fichero: " << total - 1 << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
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
  
    
    EcoCityMoto eco;
    eco.cargarClientes("clientes_v2.csv");
    eco.cargarMotos("motos.txt");
    
    cout<<"Altura del arbol: "<<eco.GetAVL()->altura()<<endl;
    cout<<"Nº de clientes: "<<eco.GetAVL()->numElementos()<<endl;
    
    
    cout<<"Nº de motos: "<<eco.Getvectordinamico()->tam()<<endl;
    
    
    return 0;
}