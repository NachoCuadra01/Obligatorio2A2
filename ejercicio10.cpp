#include <iostream>
#include <string>
#include <climits>

using namespace std;

void acertijos_bt(string* palabras, long long* sumados, long long& mejorRes, int cant, bool* visitados, int* valor, bool* noCero, int columna, int fila, int suma){

    if(columna == palabras[cant - 1].length()){
        if(suma != 0) return;

        long long* numeros = new long long[cant];

        for(int i = 0; i < cant; i++){
            numeros[i] = 0;
            for(int j = 0; j < palabras[i].length(); j++){
                numeros[i] = numeros[i] * 10 + valor[palabras[i] [j] - 'A'];
            }
        }

        long long resultado = numeros[cant - 1];

        bool mejor = false;
        if (resultado < mejorRes) mejor = true;
        
        if(resultado == mejorRes){
            int i = 0;
            while(i < cant - 1 && numeros[i] == sumados[i]){
                i++;
            }

            if(i < cant - 1){
                if (numeros[i] < sumados[i]) mejor = true;
                else mejor = false;
            }
        }

        if(mejor){
            mejorRes = resultado;
            for(int i = 0; i < cant; i++){
                sumados[i] = numeros[i];
            }
        }

        delete[] numeros;
        return;
    }

    if(fila < cant - 1){
        int pos = (int)palabras[fila].length() - 1 - columna;
        if(pos < 0){
            acertijos_bt(palabras, sumados, mejorRes, cant, visitados, valor, noCero, columna, fila + 1, suma);
            return;
        }

        int letra = palabras[fila][pos] - 'A';

        if(valor[letra] != -1){
            acertijos_bt(palabras, sumados, mejorRes, cant, visitados, valor, noCero, columna, fila + 1, suma + valor[letra]);
        }
        else{
            for(int i = 0; i < 10; i++){
                if(!visitados[i] && (i != 0 || !noCero[letra])){
                    valor[letra] = i;
                    visitados[i] = true;

                    acertijos_bt(palabras, sumados, mejorRes, cant, visitados, valor, noCero, columna, fila + 1, suma + i);
                    valor[letra] = -1;
                    visitados[i] = false;
                }
            }
        }
    }
    else{

        int pos = palabras[cant - 1].length() - 1 - columna;
        int letra = palabras[cant - 1][pos] - 'A';

        int digito = suma % 10;
        int acarreo = suma / 10;

        if(valor[letra] != -1){
            if(valor[letra] == digito){
                acertijos_bt(palabras, sumados, mejorRes, cant, visitados, valor, noCero, columna + 1, 0, acarreo);
            }
        }
        else{
            if(!visitados[digito] && (digito != 0 || !noCero[letra])){

                valor[letra] = digito;
                visitados[digito] = true;

                acertijos_bt(palabras, sumados, mejorRes, cant, visitados, valor, noCero, columna + 1, 0, acarreo);

                valor[letra] = -1;
                visitados[digito] = false;
            }
        }
    }
}


void acertijos(string* palabras, int cant){

    bool* visitados = new bool[10]();
    bool* noCero = new bool[26]();
    int* valor = new int[26];

    long long mejorRes = LLONG_MAX;
    long long* sumados = new long long[cant];

    for(int i = 0; i < 26; i++){
        valor[i] = -1;
    }

    int mayorLargo = 0;

    for(int i = 0; i < cant; i++){

        if(palabras[i].length() > 1){
            noCero[palabras[i][0] - 'A'] = true;
        }

        if(i < cant - 1 && palabras[i].length() > mayorLargo){
            mayorLargo = palabras[i].length();
        }
    }

    int largoRes = palabras[cant - 1].length();

    if(largoRes == mayorLargo){
        acertijos_bt(palabras, sumados, mejorRes, cant, visitados, valor, noCero, 0, 0, 0);
    }

    if(mejorRes == LLONG_MAX){
        cout << "imposible" << endl;
    }
    else{

        for(int i = 0; i < cant - 1; i++){

            if(i > 0){
                cout << " + ";
            }

            cout << sumados[i];
        }

        cout << " = " << mejorRes << endl;
    }

    delete[] visitados;
    delete[] noCero;
    delete[] valor;
    delete[] sumados;
}


int main(){

    int cantAcert;
    cin >> cantAcert;

    for(int i = 0; i < cantAcert; i++){

        int cant;
        cin >> cant;

        string* palabras = new string[cant + 1];

        for(int j = 0; j < cant + 1; j++){
            cin >> palabras[j];
        }

        acertijos(palabras, cant + 1);

        delete[] palabras;
    }

    return 0;
}