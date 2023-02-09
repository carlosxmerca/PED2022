/******************************************************************************

CP10 Ejemplo: POO, números aleatorios, punteros y ficheros.

*******************************************************************************/
#include <iostream>
#include "user.hpp"
#include "messages.hpp"

using namespace std;

void login(User *user);
void updatePassword(User *user);
void accessSecretInformation(User user);

int main()
{
    cout << "CP10 Ejemplo: POO, números aleatorios y punteros.\n";
    
    User myUser = User("carlosxmerca", 10);
    myUser.showCredentials();
    
    bool go = true;
    int option = 0;
    do {
        cout << "\n1) Iniciar sesion\n";
        cout << "2) Actualizar contrasena\n";
        cout << "3) Ver informacion confidencial\n";
        cout << "4) Cerrar sesion\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> option; cin.ignore();
        
        switch(option) {
            case 1: login(&myUser); break;
            case 2: updatePassword(&myUser); break;
            case 3: accessSecretInformation(myUser); break;
            case 4: myUser.logout(); break;
            case 5: go = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    } while(go);
    
    return 0;
}

void login(User *user) {
    string username, password;
    cout << "--- Iniciando sesion ---\n";
    
    cout << "username: ";
    getline(cin, username);
    cout << "password: ";
    getline(cin, password);
    
    (*user).login(username, password);
    if ((*user).isLoggedIn())
        logedInMessage();
    else 
        cout << "Me estan hackeando!!\n";
}

void updatePassword(User *user) {
    int length;
    cout << "--- Actualizando contraseña ---\n";
    cout << "Longuitd de contrasena: ";
    cin >> length; cin.ignore();
    
    // Update original user
    (*user).setPassword(length);
    (*user).showCredentials();
}

void accessSecretInformation(User user) {
    if (!user.isLoggedIn()) {
        cout << "ACCESO RESTRINGIDO!!!\n";
        return;
    }
    
    secretMessage();
}
