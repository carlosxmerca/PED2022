// queue.hpp
#include <iostream>
#include <string>
using namespace std;

// Registros a almacenar: cliente
struct cliente {
    string usuario;
    int donas;
};
typedef struct cliente Cliente;

/* Utilizaremos el identificador T 
Para referirnos el Cliente
Si cambiaramos de struct no habria 
que reemplazarlo en todas las funciones
Solo cambiar el tipo de dato que es T */

typedef Cliente T;
const T noValido = {"", -1};

// Estructuras de nodo y cola
struct Nodo{
    T elemento;
    struct Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};

// Interfaz de funciones a implementar
void initialize(Cola *q);
bool empty(Cola *q);
T front(Cola *q);
T back(Cola *q);
void enqueue(Cola *q, T x);
T dequeue(Cola *q);
int size(Cola *q);