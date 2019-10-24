/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UTM.h
 * Author: Miguel González García y Fernando Jiménez Quesada
 *
 * Created on 3 de octubre de 2019, 13:58
 */

#ifndef UTM_H
#define UTM_H
#include <iostream>

using namespace std;

 class UTM{
 private:
    double latitud;
    double longitud;
 public:
    UTM (double _lat=0.0, double _long=0.0): latitud(_lat), longitud (_long){}
    double GetLongitud() const {
    return longitud;
    }

    double GetLatitud() const {
        return latitud;
    }
    
    friend ostream& operator<<(ostream & os, const UTM & obj)
    {
    return os << "Latitud: " << obj.latitud << " | " << "Longitud: " << obj.longitud << "\n";
    }
    
 };

#endif /* UTM_H */

