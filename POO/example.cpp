//   __      ___     _                                              
//   \ \    / (_)   | |                                             
//    \ \  / / _  __| | ___  ___     __ _  __ _ _ __ ___   ___  ___ 
//     \ \/ / | |/ _` |/ _ \/ _ \   / _` |/ _` | '_ ` _ \ / _ \/ __|
//      \  /  | | (_| |  __/ (_) | | (_| | (_| | | | | | |  __/\__ \
//       \/   |_|\__,_|\___|\___/   \__, |\__,_|_| |_| |_|\___||___/
//                                   __/ |                          
//                                  |___/                                                                                                        

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

using namespace std;

class VideoGame {
    private:
        string title;
        string platform; 
        int year; 
        int hoursPlayed;
        
    public:
        void showVideoGame();
        void addHoursPlayed(int);
        
        VideoGame(string _title, string _platform, int _year) { 
          title = _title;
          platform = _platform;
          year = _year;
          hoursPlayed = 0;
        }
};

void VideoGame::showVideoGame() {
    cout << "----- Video juego -----\n";
    cout << "Titulo: " << title << "\n"; 
    cout << "Plataforma: " << platform << "\n"; 
    cout << "Anio: " << year << "\n"; 
    cout << "Horas de juego: " << hoursPlayed << "\n"; 
}

void VideoGame::addHoursPlayed(int hours) {
    hoursPlayed += hours;
}

// System main functions
void addVideoGame(vector<VideoGame>& games_collection);
void showVideoGames(vector<VideoGame>& games_collection);
void addHoursToVideoGame(vector<VideoGame>& games_collection);
void addHoursToAllVideoGames(vector<VideoGame>& games_collection);

int main() {
    // Structure to store games
    vector<VideoGame> games_collection;
    
    /* initialize random seed */
    srand (time(NULL));
  
    // Test games 
    VideoGame fifa_2022("Fifa", "PS5", 2022);
    VideoGame mario_kart("Mario kart", "Switch", 2021);
    
    fifa_2022.addHoursPlayed(200);
    mario_kart.addHoursPlayed(10);
    
    games_collection.push_back(fifa_2022);
    games_collection.push_back(mario_kart);
    
    bool go = true;
    do{
        int option = 0;
        cout << "\n1) Agregar video juego a la coleccion\n";
        cout << "2) Mostrar coleccion de video juegos\n";
        cout << "3) Agregar horas jugadas a un juego\n";
        cout << "4) Agregar horas jugadas a todos los juegos\n";
        cout << "5) Salir\n";
        cout << "Opcion elegida: ";
        cin >> option; cin.ignore();
        
        switch(option){
            case 1: addVideoGame(games_collection); break;
            case 2: showVideoGames(games_collection); break;
            case 3: addHoursToVideoGame(games_collection); break;
            case 4: addHoursToAllVideoGames(games_collection); break;
            case 5: go = false; break;
            default: cout << "Opcion invalida!\n"; break;
        }
    }while(go);
    
    return 0;
}

// System main functions

void addVideoGame(vector<VideoGame>& games_collection) {
    string tmp_title, tmp_platform;
    int tmp_year;
    
    cout << "Titulo: \n";
    getline(cin, tmp_title);
    cout << "Plataforma: \n";
    getline(cin, tmp_platform);
    cout << "Anio: \n";
    cin >> tmp_year; cin.ignore();
    
    VideoGame tmp_game(tmp_title, tmp_platform, tmp_year);
    games_collection.push_back(tmp_game);
}

void showVideoGames(vector<VideoGame>& games_collection) {
    cout << "\n----- Coleccion de video juegos ----- \n";
    for (auto game = games_collection.begin(); game != games_collection.end(); ++game)
        (*game).showVideoGame();
}

void addHoursToVideoGame(vector<VideoGame>& games_collection) {
    int hours = 0;
    int i = 0;
    int index = 0;
    
    cout << "\nSelecciona de la collecion: \n";
    for (auto game = games_collection.begin(); game != games_collection.end(); ++game) {
        cout << "------------------\n";
        cout << "Indice: " << i << "\n";
        (*game).showVideoGame();
        i++;
    }
    
    cout << "Indice seleccionado:";
    cin >> index; cin.ignore();
    cout << "Horas a agregar:";
    cin >> hours; cin.ignore();
    
    games_collection[index].addHoursPlayed(hours);
    cout << "\nHoras de juego agregadas! \n";
}

void addHoursToAllVideoGames(vector<VideoGame>& games_collection) {
    int random = rand() % 1000 + 1;
    for (auto game = games_collection.begin(); game != games_collection.end(); ++game) {
        (*game).addHoursPlayed(random);
    }
    cout << "\nHoras de juego agregadas a toda la coleccion! \n";
}
