#include <iostream>
using namespace std;

struct Cancion {
    string artist;
    string title;
    int time;
    int size;
};

void buscarCancion(Cancion cancionero[100], int cantC) {
    char n = 164;
    string search;
    int found = 1;
    cin.ignore();
    cout << "Que cancion quiere buscar?" << endl;
    getline(cin,search);


    for(int i = 0; i < cantC; i++) {
        if(cancionero[i].artist.find(search) != string::npos || cancionero[i].title.find(search) != string::npos) {
            cout << "Cancion encontrada. Es la numero " << i+1 << endl;
            cout << "Artista: " << cancionero[i].artist << endl;
            cout << "Titulo: " << cancionero[i].title << endl;
            cout << "Duracion: " << cancionero[i].time << "s" << endl;
            cout << "Tama" << n << "o: " << cancionero[i].size << endl;
            found = 0;
        }
    }

    if (found) cout << "No se ha encontrado la cancion" << endl;
}

int ingresarCanciones (Cancion cancionero[100], int cantC) {
    char n = 164;
    string artist, title;
    int time, size;

    cout << "Ingrese el nombre del artista: " << endl;
    cin >> artist;

    cout << "Ingrese el nombre de la cancion: " << endl;
    cin.ignore();
    getline(cin,title);

    cout << "Ingrese la duracion en segundos: " << endl;
    cin >> time;

    cout << "Ingrese tama" << n << "o en kb: " << endl;
    cin >> size;

    Cancion cancion = {artist, title, time, size};
    cancionero[cantC] = cancion;
    cantC++;
    return cantC;
}

void imprimirCancionero(Cancion cancionero[100], int cantC) {
    char n = 164;
    for (int i = 0; i < cantC; i++) {
        cout << i+1 << "- " << "Titulo: " << cancionero[i].title << endl;
    }
}

int main(void) {
    Cancion cancionero[100];
    int cantC = 0;

    while (1) {
        cout << "Elija una opcion: " << endl;
        cout << "\t1) Agregar cancion" << endl;
        cout << "\t2) Buscar cancion" << endl;
        cout << "\t3) Imprimir cancionero" << endl;
        cout << "\t4) Salir" << endl;

        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                cantC = ingresarCanciones(cancionero, cantC);
                break;
            case 2:
                buscarCancion(cancionero, cantC);
                break;
            case 3:
                imprimirCancionero(cancionero, cantC);
                break;
            case 4:
                return 0;
        }
    }
}