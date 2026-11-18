#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

long long cantRemontadasAux(int* puestos, int* auxiliar, int inicio, int final) {
    if (inicio >= final) {
        return 0;
    }

    int medio = inicio + (final - inicio) / 2;

    long long cant = cantRemontadasAux(puestos, auxiliar, inicio, medio);
    cant += cantRemontadasAux(puestos, auxiliar, medio + 1, final);

    int j = medio + 1;

    for (int i = inicio; i <= medio; i++) {
        while (j <= final && puestos[i] > 2 * puestos[j]) {
            j++;
        }

        cant += j - (medio + 1);
    }

    int izquierda = inicio;
    int derecha = medio + 1;

    for (int i = inicio; i <= final; i++) {
        if (derecha > final ||
            (izquierda <= medio && puestos[izquierda] <= puestos[derecha])) {
            auxiliar[i] = puestos[izquierda];
            izquierda++;
        } else {
            auxiliar[i] = puestos[derecha];
            derecha++;
        }
    }

    for (int i = inicio; i <= final; i++) {
        puestos[i] = auxiliar[i];
    }

    return cant;
}

long long cantRemontadas(int* puestos, int largo) {
    int* auxiliar = new int[largo];

    long long cant = cantRemontadasAux(puestos, auxiliar, 0, largo - 1);

    delete[] auxiliar;
    return cant;
}

int main() {
    int largo;
    cin >> largo;
    int* puestos = new int[largo];

    for (int i = 0; i < largo; i++) {
        cin >> puestos[i];
    }

    cout << cantRemontadas(puestos, largo);
    return 0;
}