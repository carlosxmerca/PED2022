#include <iostream>
#include <cmath>

using namespace std;

int sumatoria(int num);
int sumatoria_potencia(int num, int pot);
int sumatoria_potencia2(int num, int pot, int i = 0);

int main()
{
    cout<<"Ejemplos de sumatoria\n";
    
    cout << "La sumatoria de los primeros 5 #naturales es: " << sumatoria(5) << "\n";
    cout << "Valor total de la sumatoria: " << sumatoria_potencia(5, 3) << "\n";
    cout << "Valor total de la sumatoria: " << sumatoria_potencia2(5, 3);
    
    return 0;
}

int sumatoria(int num) {
    if (num == 1) 
        return 1;
    else 
        return num + sumatoria(num-1);
}

// 5 + ...
//     4 + ...
//          3 + ...
//              2 + ...
//                      1

int sumatoria_potencia(int num, int pot) {
    if (pot == 0) 
        return 1;
    else 
        return pow(num, pot) + sumatoria_potencia(num, pot-1);
}

/*
sumatoria_potencia(5, 3); -> 156
x = 5
n = 3
resultado = 156

5^3 + ... 
        5^2 + ... 
                5^1 + ... 
                        5^0
*/

int sumatoria_potencia2(int num, int pot, int i) {
    if (i == pot) 
        return pow(num, i);
    else
        return pow(num, i) + sumatoria_potencia2(num, pot, i+1);
}

/*
int sumatoria_potencia2(int num, int pot, int i = 0);

sumatoria_potencia2(5, 3); -> 156
x = 5
n = 3
i = 0
resultado = 156

5^0 + ... 
        5^1 + ... 
                5^2 + ... 
                        5^3
*/
