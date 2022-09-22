// Determinar si una palabra es palindrome
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void mostrarPalabra(char palabra[], int n);
void palindrome(char palabra[], int n);
void palindrome_recursivo(char palabra[], char respaldo[], int n, int i, int j);

int main()
{
    string entrada;
    int n;
    
    cout << "Palabra palindrome:\n";
    getline(cin, entrada);
    n = entrada.length();
    
    // String -> char array
    char palabra[n+1];
    strncpy(palabra, entrada.c_str(), n);
    
    cout << "Palabra a revisar:\n";
    mostrarPalabra(palabra, n);
    
    // Sin utilizar recursion
    palindrome(palabra, n);
    
    // Utilizando recursion
    char respaldo[n+1];
    strncpy(respaldo, palabra, n);
    
    palindrome_recursivo(palabra, respaldo, n, n-1, 0);
    
    return 0;
}

void mostrarPalabra(char palabra[], int n) {
    for (int i = 0; i < n; i++)
        cout << palabra[i];
    cout << "\n\n";
}

void palindrome(char palabra[], int n) {
    char respaldo[n+1];
    strncpy(respaldo, palabra, n);
    
    int j = 0; // Recorrido hacia adelante
    for (int i = n-1; i >= 0; i--) { // Recorrido hacia atras
        if (palabra[i] != respaldo[j]) {
            cout << "La palabra NO es palindrome!\n";
            return;
        }
        j++;
    }
    cout << "La palabra es palindrome!\n";
}

// n -> tamaño de la palabra
// i -> variable que recorre la palabra original (de manera inversa)
// j -> variable que recorre la palabra de respaldo (de manera normal)
void palindrome_recursivo(char palabra[], char respaldo[], int n, int i, int j) {
    // cout << i << " " << j << "\n";
    // cout << palabra[i] << " " << respaldo[j] << "\n";
    if (palabra[i] != respaldo[j]) {
        cout << "La palabra NO es palindrome!\n";
        return;
    }
    if (i == 0) {
        // CASO BASE
        cout << "La palabra es palindrome!\n";
    } else {
        // CASO RECURSIVO
        palindrome_recursivo(palabra, respaldo, n, i-1, j+1);
    }
}
