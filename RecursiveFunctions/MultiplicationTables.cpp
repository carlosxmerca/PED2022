#include <iostream>

using namespace std;

void tablas_mult(int num, int tabla = 1);
void tablas_mult_2(int num, int tabla = 1); // (int tabla = 1) -> es para indicar un valor por defecto

int main()
{
    cout << "Tablas de multiplicar\n";
    
    int x = 5;
    cout << "Imprimiendo la tabla del " << x << "\n";
    tablas_mult(x);
    tablas_mult_2(x); // Imprimiendo tablas

    return 0;
}

void tablas_mult(int num, int tabla) {
    cout << num << " x " << tabla << " = " << (num * tabla) << "\n";
    
    if (tabla < 10)
        tablas_mult(num, tabla+1);
    else 
        cout << "Ejecucion finalizada \n\n";
}

void tablas_mult_2(int num, int tabla) {
    if (tabla <= 10) {
        cout << num << " x " << tabla << " = " << (num * tabla) << "\n";
        tablas_mult_2(num, tabla+1);
    } 
    else 
        cout << "Ejecucion finalizada \n";
}

/*
** iteracion 1:
num: 5
tabla: 1

imprimir: num x tabla

** iteracion 2:
num: 5
tabla: 2

imprimir: num x tabla

** iteracion 3:
num: 5
tabla: 3

imprimir: num x tabla
*/
