/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EcoCityMoto.cpp
 * Author: Fernando
 * 
 * Created on October 24, 2019, 12:07 PM
 */

#include "EcoCityMoto.h"

EcoCityMoto::EcoCityMoto() {
}

EcoCityMoto::EcoCityMoto(const EcoCityMoto& orig) {
}

EcoCityMoto::~EcoCityMoto() {
}

Moto* EcoCityMoto::LocalizaMotoCercana(UTM &ubicacion){
    Moto *moto;
    
    double maxDistancia = 9999999999, distancia;
    for(int i = 0; i<motos.tam()-1; i++){
        if(motos[i].getStatus()==BLOQUEADA){
            distancia=ubicacion.distancia(motos[i].getPosicion());
            if(distancia<maxDistancia){
                maxDistancia=distancia;
                moto = &motos[i];
            }
        }
    }
    
    return moto;
}

void EcoCityMoto::desbloqueaMoto(Moto *moto, Cliente *cli){
    moto->seActiva(cli);  
    idUltimo++;  
}

void EcoCityMoto::cargarClientes(std::string filename){
    std::ifstream fe; //Flujo de entrada
    std::string linea; //Cada linea tiene un clienete
    int total = 0; //Contador de lineas o clientes

    //Variables auxiliares para almacenar los valores leidos
    std::string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon;



    //Asociamos el flujo al fichero 
    fe.open(filename);

    if (fe.good()) {
        //Mientras no se haya llegado al final del fichero
        while (!fe.eof()) {
            getline(fe, linea); //Toma una linea del fichero
            std::stringstream ss; //Stream que trabaja sobre buffer interno         

            if (linea != "") {
                ++total;
            }

            if (total >= 1) {
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
                Cliente client(dni, pass, nombre, direccion, dlat, dlon, this);
                clientes.inserta(client);
                if (total % 100 == 0) {
                    std::cout << "Leido cliente " << total << "\n  ";
                }
            }
        }

        std::cout << "Total de clientes en el fichero: " << total - 1 << std::endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        std::cerr << "No se puede abrir el fichero" << std::endl;
    }
}

void EcoCityMoto::cargarMotos(std::string filename){
    std::ifstream fe; //Flujo de entrada
    std::string linea; //Cada linea tiene un clienete
    int total = 0; //Contador de lineas o clientes
    //Variables auxiliares para almacenar los valores leidos
    std::string mat, latitud, longitud, estado;
    double dlat, dlon;
    //Asociamos el flujo al fichero 
    fe.open(filename);

    if (fe.good()) {
        //Mientras no se haya llegado al final del fichero
        while (!fe.eof()) {
            getline(fe, linea); //Toma una linea del fichero
            std::stringstream ss; //Stream que trabaja sobre buffer interno         

            if (linea != "") {
                ++total;
            }

            if (total >= 1) {
                //Inicializamos el contenido de ss
                ss << linea;

                //Leemos la matricula
                getline(ss, mat, ';'); //El caracter ; se lee y se elimina de ss

                //Leemos el estado
                getline(ss, estado, ';'); //El carater ; se lee y se elimina de ss

                //Leemos la latitud y longitud
                getline(ss, latitud, ';'); //El carater ; se lee y se elimina de ss
                getline(ss, longitud, ';'); //El carater ; se lee y se elimina de ss

                dlat = stod(latitud);
                dlon = stod(longitud);
                int aux = stoi(estado);

                //con todos los atributos leidos, se crea la moto
                Moto moto(mat, dlat, dlon, aux);
                motos.insertar(moto);
                if (total % 100 == 0) {
                    std::cout << "Leido cliente " << total << "\n  ";
                }
            }
        }

        std::cout << "Total de clientes en el fichero: " << total - 1 << std::endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        std::cerr << "No se puede abrir el fichero" << std::endl;
    }
}