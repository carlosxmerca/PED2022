/******************************************************************************

1. Cree un programa que contenga una estructura de tipo [estudiante] que deberá almacenar: nombre y edad
2. Inicialice los valores de la estructura a los que sean de su preferencia
3. Cree un puntero que apunte a la dirección de memoria de la estructura recién creada
4. Cree un puntero doble que apunte a el puntero simple creado en el paso 3
5. Utilizando el puntero simple modifique los valores previamente almacenados en la estructura
6. Muestre los valores almacenados, utilizando una función que reciba la estructura Estudiante
7. Utilizando una función que utilice el puntero doble cambie la edad del registro
8. Utilizando una función que utilice el puntero simple cambie el nombre del registro
9. Muestre los valores almacenados, utilizando una función que reciba el puntero simple.
10. Intente modificar la edad del registro usando una función que reciba la estructura Estudiante (no punteros)
11. Compruebe que ningún cambio fue hecho en el registro

Opcionalmente: Utilizar typedef

*******************************************************************************/
#include <iostream>
using namespace std;

struct estudiante {
	string nombre;
	int edad;
};
typedef struct estudiante Estudiante;

void mostrarEstudiante(Estudiante unEstudiante);
void mostrarEstudiantePuntero(Estudiante *puntero);
void cambiarEdad(Estudiante **punteroDoble, int edad);
void cambiarNombre(Estudiante *puntero, string nombre);
void cambiarEdadSinPuntero(Estudiante estudiante, int edad);

int main() {
    // 1 y 2. Creando un registro de estudiante y inicializando sus datos
	Estudiante carlos;
	carlos.nombre = "Carlos";
	carlos.edad = 20;
    
    // 3 y 4
	Estudiante *puntero = &carlos; // Creamos un puntero que apunte a la direccion de memoria de la struct
	Estudiante **punteroDoble = &puntero; // Puntero doble que apunta al puntero simple
	// punteroDoble -> puntero -> Estudiante (carlos)
	
	// 5. Modificando valores de la estructura usando el puntero simple
	cout << "Modificando nombre...\n";
	(*puntero).nombre = "Carlos Mercado";
	cout << "Modificando edad..\n";
	(*puntero).edad = 21;
	
	// 6. Mostrando valores actuales de la estructura
	cout << "Accediendo al registro:\n";
	mostrarEstudiante(carlos);
	
	// 7 y 8. Modificando valores de la estructura usando el puntero doble
	cout << "Modificando edad y nombre...\n";
	cambiarEdad(punteroDoble, 22); // Modificamos la edad con una funcion que recibe un puntero doble y la edad
	cambiarNombre(puntero, "Carlos"); // Modificamos el nombre con una funcion que recibe un puntero simple y el nombre
	
	// 9. Mostrando valores actuales de la estructura
	cout << "Accediendo al registro:\n";
	mostrarEstudiantePuntero(puntero);
	
	// 10 y 11
	cambiarEdadSinPuntero(carlos, 19);
	cout << "Accediendo al registro:\n";
	/* La edad no sera 19 por que no modificamos la estructura carlos
	sino una copia de ella que fue enviada a la funcion cambiarEdadSinPuntero()
	*/
	mostrarEstudiantePuntero(puntero);
	
	return 0;
}

void mostrarEstudiante(Estudiante unEstudiante) {
    cout << "Nombre: " << unEstudiante.nombre << ", Edad: " << unEstudiante.edad << "\n\n";
}

void mostrarEstudiantePuntero(Estudiante *puntero) {
    cout << "Nombre: " << (*puntero).nombre <<  ", Edad: " << (*puntero).edad << "\n\n";
}

void cambiarEdad(Estudiante **punteroDoble, int edad) {
    (**punteroDoble).edad = edad;
}

void cambiarNombre(Estudiante *puntero, string nombre) {
    (*puntero).nombre = nombre;
}

void cambiarEdadSinPuntero(Estudiante estudiante, int edad) {
    estudiante.edad = edad;
}
