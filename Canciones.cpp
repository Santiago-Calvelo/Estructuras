#include <iostream>
using namespace std;

struct Cancion {
    string artist;
    string title;
    int time;
    int size;
};

void buscarCancion(Cancion cancionero[100], int cantC) {
    int idx = -1;
    string search;
    cout << "Ingrese un texto que contenga la cancion (titulo, artista): ";
    cin >> search;


    for (int i = 0; i < cantC; i++) {
        if     (cancionero[i].artist == search) { idx = i; break; }
        else if (cancionero[i].title == search) { idx = i; break; }
    }
}

int ingresarCanciones (Cancion cancionero[100], int cantC) {
    cantC++;
    string artist, title;
    int time, size;

    cout << "Ingrese el nombre del artista: " << endl;
    cin >> artist;

    cout << "Ingrese el nombre de la cancion: " << endl;
    cin >> title;

    cout << "Ingrese la time en segundos: " << endl;
    cin >> time;

    cout << "Ingrese tamaño en kb: " << endl;
    cin >> size;

    Cancion cancion = {artist, title, time, size};
    cancionero[cantC] = cancion;
    
    return cantC;
}

void imprimirCancionero(Cancion cancionero[100], int cantC) {
    char n = 164;
    for (int i = 0; i < cantC; i++) {
        cout << "Cancion: " << i+1 << endl;
        cout << "\tArtista: " << cancionero[i].artist << endl;
        cout << "\tTitulo: " << cancionero[i].title << endl;
        cout << "\tDuracion: " << cancionero[i].time << endl;
        cout << "\tTama" << n << "o: " << cancionero[i].size << endl;
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

        int choice;
        cin >> choice,

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
        }
    }
}