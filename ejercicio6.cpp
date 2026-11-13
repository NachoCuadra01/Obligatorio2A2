#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

struct Cartel{
    int placa;
    int cant;
};


void placa(Cartel* c, int tam, int n){
    int* array = new int[n];
    int actual = 0;
    int cantElementos = 0;
    for (int i = 0; i < tam && cantElementos < n; i++){
        while (c[i].cant >= 2 && cantElementos < n){
            cantElementos +=2;
            c[i].cant -= 2;
            array[actual] = c[i].placa;
            array[n-1-actual] = c[i].placa;
            actual++;
        }
    }

    bool puesto = false;
    for (int i = 0; i < tam && !puesto; i++){
        if (c[i].cant == 1){
            array[n/2] = c[i].placa;
            puesto = true;
        }
    }

    for (int i = 0; i < n; i++) {
    if (i > 0) {
        cout << ' ';
    }
    cout << array[i];
    }

    cout << '\n';
    delete[] array;
}   


    
int main() {
    int n;
    cin >> n;

    int cantidad[1001] = {};

    for (int i = 0; i < n; i++) {
        int numero;
        cin >> numero;
        cantidad[numero]++;
    }

    Cartel c[1001];
    int tam = 0;
    int largo = 0;
    bool sobra = false;

    for (int i = 1000; i >= 0; i--) {
        if (cantidad[i] > 0) {
            c[tam].placa = i;
            c[tam].cant = cantidad[i];
            tam++;

            largo += (cantidad[i] / 2) * 2;

            if (cantidad[i] % 2 == 1) {
                sobra = true;
            }
        }
    }

    if (sobra) {
        largo++;
    }

    placa(c, tam, largo);

    return 0;
}