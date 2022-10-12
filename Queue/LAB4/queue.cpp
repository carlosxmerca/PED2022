// queue.cpp
#include <iostream>
#include <string>
#include "queue.hpp"
using namespace std;

// Implementacion de headers -> queue.hpp
// Funciones de cola

void initialize(Cola *q){
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q){
    return (q->frente == NULL) ? true : false;
}

T front(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->frente)->elemento;
}

T back(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enqueue(Cola *q, T x){
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;
    
    if(q->final == NULL)
        q->frente = unNodo;
    else
        (q->final)->siguiente = unNodo;
        
    q->final = unNodo;
}

// Continuacion queue.cpp

T dequeue(Cola *q){
    if(empty(q)){
        cout << "Underflow!" << endl;
        return noValido;
    }
    
    Nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;
    
    if(q->frente == NULL)
        q->final = NULL;
    delete(unNodo);
    
    return x;
}

// Devuelve el numero de elementos que contiene la cola
int size(Cola *q) {
    if (empty(q)) // Si la cola esta vacia hay 0 elementos
        return 0;
    
    /* Si la cola no esta vacia se recorren los nodos
    hasta llegar al final y por cada nodo se incrementa el contador */
    Nodo *unNodo = q->frente;
    int contador = 1;
    
    while(unNodo->siguiente != NULL) {
        unNodo = unNodo->siguiente;
        contador++;
    }

    return contador;
}
