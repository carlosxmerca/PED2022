#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>

using namespace std;

class User {
    private:
        string username;
        string password;
        bool logged;
    
    public:
        void setPassword(int length);
        void showCredentials();
        void login(string _username, string _password);
        void logout();
        bool isLoggedIn();
        
        User(string _username, int _length) {
            username = _username;
            logged = false;
            setPassword(_length);
        }
};

/**
 * Update/set user's password.
 *
 * ADVERTENCIA: funcion con proposito didactico
 * Nunca usen esta funcion en un proyecto real/profesional
 * ya que este generador de contraseñas carece de entropia y verdadera aletoriedad
 * es decir sigue un patron predecible y puede ser facilmente vulnerado.
 * 
 * Si les interesa el tema investiguen algoritmos de HASH seguros.
 * https://code-maze.com/csharp-hashing-salting-passwords-best-practices/
 * 
 * @param length -> number of characters that the password will contain.
 */
void User::setPassword(int length) {
    if (length < 4) {
        cout << "\nLonguitud minima de contraseña (4) caracteres\n";
        return;
    }
    
    // initialize random seed
    srand(time(NULL));
    
    // Diccionarios
    int n = 26;
    char dictionary_minus[n] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm', 'n', 'l', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    int m = 10;
    char dictionary_nums[m] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    // Construir contraseña
    string newPassword = "";
    
    for (int i = 0; i < length; i++) {
        int case_random = rand() % 1000 + 1;

        int d_minus_case = case_random % (n - 1);
        int d_nums_case = case_random % (m - 1);
        
        if (case_random % 2 == 0)
            newPassword += dictionary_minus[d_minus_case];
        else 
            newPassword += dictionary_nums[d_nums_case];
    }
    
    // Change user's current password
    password = newPassword;
}

void User::showCredentials() { 
    // Si corre en linea usar...
    // cout << "Username: " << username << "\n";
    // cout << "Password: " << password << " (" << password.length() << ")" << "\n";
    
    // Si corre en local usar...
    ofstream file;
    file.open("secrets.txt", ios::app | ios::out);
    
    if(!file.is_open()) {
        cout << "Error opening file";
        return;
    }
    
    file << "Username: " << username << "\n";
    file << "Password: " << password << " (" << password.length() << ")" << "\n";
    file << "##################################" << endl;
    file.close();
    
    cout << "credenciales exportadas!\n";
}

void User::login(string _username, string _password) {
    logged = username == _username && password == _password;
}

void User::logout() {
    cout << "Cerrando sesión...\n";
    logged = false;
}

bool User::isLoggedIn() {
    return logged;
}
