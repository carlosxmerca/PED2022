/******************************************************************************
Propuesta de solucion CP3: Grupos 7 y 15
Nota: Hay cosas que se pueden hacer de varias formas usando las mismas bases
Prueba en linea: https://onlinegdb.com/AXgHzBF0h
*******************************************************************************/
// Sin utilizar libreria <stack>
#include <iostream>
#include <string>

using namespace std;

struct pizza {
  string nombre;
  float precio;
  int porciones;
};
typedef struct pizza Pizza;

// Nodos a utilizar para la pila
struct nodo{
    Pizza elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Stack;

// Funciones base para trabajar con pilas
void initialize(Stack *s);
bool empty(Stack *s);
void push(Stack *s, Pizza pizza);
Pizza pop(Stack *s);
Pizza top(Stack *s);

// Funciones extra
void mostrarPizza(Pizza unaPizza);
void mostrarPila(Stack *s);
void mostrarPilaSinDestruir(Stack *s);
void size(Stack *s);

int main()
{
    cout << "Pila de pizzas almacenadas\n";
    
    // Incializando la pila de pizzas
    Stack pizza_stack;
    initialize(&pizza_stack);
    
    // Declarando las pizzas a utilizar
    Pizza pizza_jamon = { "Pizza de jamon", 13.50, 12 };
    Pizza pizza_queso = { "Pizza de queso", 15.50, 16 };
    Pizza pizza_peperoni = { "Pizza de peperoni", 11.50, 16 };
    
    // Agregando las pizzas a la pila
    push(&pizza_stack, pizza_jamon);
    push(&pizza_stack, pizza_queso);
    push(&pizza_stack, pizza_peperoni);
   
    // Menu de opciones 
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Mostrar pila\n";
        cout << "2) Mostrar pila (sin destruir)\n";
        cout << "3) Mostrar numero de elementos (sin destruir)\n";
        cout << "4) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: mostrarPila(&pizza_stack); break;
            case 2: mostrarPilaSinDestruir(&pizza_stack); break;
            case 3: size(&pizza_stack); break;
            case 4: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);
    
    return 0;
}

// Funciones extra

void mostrarPizza(Pizza unaPizza) {
    cout << "*****************\n";
    cout << "Nombre: " << unaPizza.nombre << "\n";
    cout << "Precio: $" << unaPizza.precio << "\n";
    cout << "porciones: " << unaPizza.porciones << "\n";
    cout << "*****************\n";
}

void mostrarPila(Stack *s) { // y Destruir al mismo tiempo
    if(empty(s)) {
        cout << "\nPila vacia\n";
        return;
    }
    
    // Mostrar la información de las pizzas dentro de la pila 
    while (!empty(s)) { // Continuar hasta que la pila este vacia
        Pizza unaPizza = top(s); // Obteniendo la pizza de "arriba" de la pila
        mostrarPizza(unaPizza);
    
        pop(s); // Eliminando la pizza ya mostrada
    }
}

// Esta funcion no era necesaria en el CP3
void mostrarPilaSinDestruir(Stack *s) {
    if(empty(s)) {
        cout << "\nPila vacia\n";
        return;
    }
    
    // La pila auxiliar apuntara al primer elemento de la pila s
    Stack aux = *s;
    // Linea 95 y 96: Misma direccion de memoria
    // cout << *s << "\n"; 
    // cout << aux << "\n";  
    do 
    {
        Pizza unaPizza = (*s)->elemento;
        mostrarPizza(unaPizza);

        *s = (*s)->siguiente;
    }
    while (*s != NULL);
    // Al finalizar el bucle la pila s apunta a NULL
    // Hacemos que la pila s vuelva a apuntar al primer nodo
    *s = aux;
}

void size(Stack *s) {
    if(empty(s)) {
        cout << "\nNumero de elementos: 0\n";
        return;
    }
    
    Stack aux = *s;
    int count = 0;
    do 
    {
        count++;
        *s = (*s)->siguiente;
    }
    while (*s != NULL);

    *s = aux;
    
    cout << "\nNumero de elementos: " << count << "\n";
}

// Implementación funciones base para trabajar con pilas

void initialize(Stack *s){
    *s = NULL;
}

bool empty(Stack *s){
    return *s == NULL;
}

void push(Stack *s, Pizza pizza){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = pizza;
    unNodo->siguiente = *s;
    
    *s = unNodo;
}

Pizza pop(Stack *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        Pizza e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else // Underflow!
        return {{" "},{0.0},{0}};
}

Pizza top(Stack *s){
    if(!empty(s))
        return (*s)->elemento;
    else // Underflow!
        return {{" "},{0.0},{0}};
}
