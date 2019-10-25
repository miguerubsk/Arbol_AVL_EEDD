/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.h
 * Author: Miguel González García y Fernando Jiménez Quesada
 *
 * Created on October 22, 2019, 4:13 PM
 */

#ifndef AVL_H
#define AVL_H
#include <iostream>

#include "ListaDEnlazada.h"

template <typename U>
class NodoAVL {
public:
    NodoAVL <U> *izq, *der;
    U dato;
    char bal; // -1, 0 , 1 para un árbol avl

    NodoAVL(U &ele) : izq(0), der(0), bal(0), dato(ele) {
    }
};

template <typename T>
class AVL {
    NodoAVL<T> *raiz;
    unsigned int numEle = 0;
private:
    int inserta(NodoAVL <T>* &c, T &dato);
    void recorreInorden(NodoAVL <T> *p, int nivel);
    NodoAVL <T>* buscaClave(T &ele, NodoAVL<T> *p);
    int altura_aux(NodoAVL<T> *p);
    void rotIzqda(NodoAVL <T>* &p);
    void rotDecha(NodoAVL <T>* &p);
    void borrar(NodoAVL<T>* p);
public:
    AVL<T>();
    AVL<T>(const AVL<T> & origen); //@TODO terminar constructor copia
    virtual ~AVL();
    void operator=(AVL<T>& orig); //@TODO terminar operador de asignacion
    bool busca(T& dato, T& result);
    bool buscaIt(T& dato, T& result);
    void recorreInorden() {
        recorreInorden(raiz, 0);
    }
    bool inserta(T &dato) {
        numEle++;
        return inserta(raiz, dato);
    }
    T recorreInordenaux(NodoAVL<T> *p, int nivel);
    void copiar(NodoAVL<T> *& dest, NodoAVL<T> * orig);
    unsigned int numElementos();
    unsigned int altura();
};

template <typename T>
AVL<T>::AVL() {
    raiz = 0;
    numEle=0;
}

template <typename T>
AVL<T>::AVL(const AVL<T> & origen) {
//    if(origen.numElementos()!=0){     
//    }
}

template <class T>
void AVL<T>::copiar(NodoAVL<T>* &dest, NodoAVL<T> * orig)
{

}

template <typename T>
void AVL<T>::operator=(AVL<T>& orig) {
    raiz = orig.raiz;
}

template<typename T>
void AVL<T>::rotIzqda(NodoAVL<T>* &p) {
    NodoAVL<T> *q = p, *r;
    p = r = q->der;
    q->der = r->izq;
    r->izq = q;
    q->bal++;
    if (r->bal < 0) q->bal += -r->bal;
    r->bal++;
    if (q->bal > 0) r->bal += q->bal;
}

template<typename T>
void AVL<T>::rotDecha(NodoAVL<T>* &p) {
    NodoAVL<T> *q = p, *l;
    p = l = q->izq;
    q->izq = l->der;
    l->der = q;
    q->bal--;
    if (l->bal > 0) q->bal -= l->bal;
    l->bal--;
    if (q->bal < 0) l->bal -= -q->bal;
}

template<typename T>
int AVL<T>::inserta(NodoAVL<T>* &c, T &dato) {
    NodoAVL<T> *p = c;
    int deltaH = 0;
    if (!p) {
        p = new NodoAVL<T>(dato);
        c = p;
        deltaH = 1;
    } else if (dato > p->dato) {
        if (inserta(p->der, dato)) {
            p->bal--;
            if (p->bal == -1) deltaH = 1;
            else if (p->bal == -2) {
                if (p->der->bal == 1) rotDecha(p->der);
                rotIzqda(c);

            }
        }
    } else if (dato < p->dato) {
        if (inserta(p->izq, dato)) {
            p->bal++;
            if (p->bal == 1) deltaH = 1;
            else if (p->bal == 2) {
                if (p->izq->bal == -1) rotIzqda(p->izq);
                rotDecha(c);

            }
        }
    }

    return deltaH;
}

template <class T>
void AVL<T>::recorreInorden(NodoAVL<T> *p, int nivel) {
    if (p) {
        recorreInorden(p->izq, nivel + 1);
        std::cout << "Procesando nodo " << p->dato;
        std::cout << " en el nivel " << nivel << std::endl;
        recorreInorden(p->der, nivel + 1);
    }
}

template <class T>
T AVL<T>::recorreInordenaux(NodoAVL<T> *p, int nivel) {
    if (p) {
        recorreInordenaux(p->izq, nivel + 1);
        return p->dato;
        recorreInordenaux(p->der, nivel + 1);
    }
}

template <class T>
unsigned int AVL<T>::numElementos() {
    return numEle;
}

template <class T>
unsigned int AVL<T>::altura() {
    return altura_aux(this->raiz);
}

template<typename T>
int AVL<T>::altura_aux(NodoAVL<T> *p) {
    if (p == 0)
        return 0;

    return 1 + std::max(altura_aux(p->der), altura_aux(p->izq));

}

template <class T>
NodoAVL<T> *AVL<T>::buscaClave(T &ele, NodoAVL<T> *p) {
    if (!p)
        return 0;
    else if (ele < p->dato)
        return buscaClave(ele, p->izq);
    else if (ele > p-> dato)
        return buscaClave(ele, p->der);
    else return p;
}

template <class T>
bool AVL<T>::busca(T &ele, T &result) {
    NodoAVL<T> *p = buscaClave(ele, raiz);
    if (p) {
        result = p->dato;
        return true;
    }
    return false;
}

template<typename T>
bool AVL<T>::buscaIt(T& dato, T& result) {
    NodoAVL<T> *aux = raiz;
    while (aux != 0) {
        if (dato < aux->dato) {
            aux = aux->izq;
        } else {
            if (dato > aux->dato) {
                aux = aux->der;
            } else {
                result = aux->dato;
                return true;
            }
        }
    }
    return false;
}

template<typename T>
void AVL<T>::borrar(NodoAVL<T>* p) {
    if (p) {
        borrar(p->izq);
        borrar(p->der);
        delete p;
        p=0;
    }
}

template <typename T>
AVL<T>::~AVL() {
    borrar(raiz);
    numEle = 0;
    raiz = 0;
}

#endif /* AVL_H */

