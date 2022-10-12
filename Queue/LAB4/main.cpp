// main.cpp
#include <iostream>
#include <string>
// Incluimos nuestra libreria de colas
#include "queue.hpp" 
using namespace std;

float PRECIO_DONAS = 1.35;
// Declarar cola a utilizar
Cola cola_clientes;

// Funciones que contienen la logica del negocio
void agregarCliente();
void mostrarCliente(Cliente cliente, bool cobrar = false);
void consultarCola(Cola *q);
void despacharCliente(Cola *q);
void mostrarTamanoCola(Cola *q);
void consularInicioyFinal(Cola *q);
void mostrarMensajeColaVacia();

int main()
{
    initialize(&cola_clientes);
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar una nueva persona a la fila\n";
        cout << "2) Consultar clientes de la fila\n";
        cout << "3) Despachar cliente\n";
        cout << "4) Consultar tamaño de la fila\n";
        cout << "5) Consultar incio y final de la cola\n";
        cout << "6) Salir\n";
        cout << "Opcion elegida: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregarCliente(); break;
            case 2: consultarCola(&cola_clientes); break;
            case 3: despacharCliente(&cola_clientes); break;
            case 4: mostrarTamanoCola(&cola_clientes); break;
            case 5: consularInicioyFinal(&cola_clientes); break;
            case 6: continuar = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(continuar);

    return 0;
}

// Continuacion main.cpp
// Implementacion funciones que contienen la logica del negocio

void agregarCliente(){
    // Creamos un nuevo cliente para completar su informacion
    Cliente nuevo_cliente;
    
    cout << "--------------------------------\n";
    cout << "--- Agregando nuevo cliente a la fila ---\n";
    cout << "Ingrese el nombre del usuario:\n";
    getline(cin, nuevo_cliente.usuario);
    cout << "Ingrese el numero de donas a comprar:\n";
    cin >> nuevo_cliente.donas;
    cin.ignore();
    
    // Agregamos el nuevo cliente a la cola de clientes
    enqueue(&cola_clientes, nuevo_cliente);
}

void mostrarCliente(Cliente cliente, bool cobrar){
    cout << "Usario: " << cliente.usuario << "\n";
    cout << "Numero de donas: " << cliente.donas << "\n";
    if (cobrar)
        cout << "Total a pagar: $" << (cliente.donas * PRECIO_DONAS) << "\n";
    cout << "--------------------------------\n";
}

void consultarCola(Cola *q){
    if (empty(q)) {
        mostrarMensajeColaVacia();
        return;
    }
    
    // Puntero uxiliar que mira al nodo del frente
    Nodo *unNodo = q->frente;
    cout << "----------- INICIO -------------\n";
    cout << "--------------------------------\n";
    // Como al cola no esta vacia se muestra el primer cliete
    mostrarCliente(unNodo->elemento);
    
    // Si aun hay mas clientes se ejecuta el while
    while(unNodo->siguiente != NULL) {
        // Nos desplazamos al nodo siguiente
        unNodo = unNodo->siguiente;
        cout << "--------------------------------\n";
        // Acciones que necesitemos realizar con los nodos
        mostrarCliente(unNodo->elemento); 
    }
    cout << "------------ FINAL -------------\n";
}

void mostrarTamanoCola(Cola *q){
    int tamano = size(q);
    cout << "\nNumero de clientes: " << tamano << "\n";
}

// Continuacion main.cpp

void consularInicioyFinal(Cola *q){
    if (empty(q)) {
        mostrarMensajeColaVacia();
        return;
    }
    
    // Traer el cliente del frente de la cola
    Cliente clienteFrente = front(q);
    cout << "----------- INICIO -------------\n";
    mostrarCliente(clienteFrente);
    
    // Traer el cliente del final de la cola
    Cliente clienteFinal = back(q);
    cout << "------------ FINAL -------------\n";
    mostrarCliente(clienteFinal);
}

void despacharCliente(Cola *q){
    if (empty(q)) {
        mostrarMensajeColaVacia();
        return;
    }
    
    // Traer el cliente del frente de la cola
    // Y al mismo tiempo eliminarlo
    Cliente cliente = dequeue(q);
    cout << "------- DESPACHANDO CLIENTE -------\n";
    mostrarCliente(cliente, true);
}

void mostrarMensajeColaVacia(){
    cout << "--------------------------------\n";
    cout << "Cola vacia!\n";
    cout << "--------------------------------\n";
}
