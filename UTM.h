/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UTM.h
 * Author: admin
 *
 * Created on 3 de octubre de 2019, 13:58
 */

#ifndef UTM_H
#define UTM_H
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

 };


#endif /* UTM_H */

