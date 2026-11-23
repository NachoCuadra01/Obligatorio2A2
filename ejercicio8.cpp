#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int maxSatisfaccion(int n, int W, int l0, int l1, int l2, int l3, int* peso, int* sat, int* cat){
    int A = l0 + 1;
    int B = l1 + 1;
    int C = l2 + 1;
    int D = l3 + 1;

    int sC = D;
    int sB = C * D;
    int sA = B * C * D;
    int sW = A * B * C * D;
    int sI = (W + 1) * sW;

    int* dp = new int[(n + 1) * sI]();

    for(int i = 1; i <= n; i++){
        int p = peso[i-1];
        int s = sat[i-1];
        int k = cat[i-1];
        for(int w = 0; w <= W; w++){
            for(int a = 0; a <= l0; a++){
                for(int b = 0; b <= l1; b++){
                    for(int c = 0; c <= l2; c++){
                        for(int d = 0; d <= l3; d++){
                            int idx = i*sI + w*sW + a*sA + b*sB + c*sC + d;

                            // Opción 1: no comprar el producto i
                            int mejor = dp[idx - sI];

                            // Opción 2: comprarlo
                            if(w >= p){
                                int base = idx - sI - p*sW; // capa i-1, peso w-p
                                if(k == 0 && a >= 1){
                                    int cand = dp[base - sA] + s;
                                    if(cand > mejor) mejor = cand;
                                }
                                if(k == 1 && b >= 1){
                                    int cand = dp[base - sB] + s;
                                    if(cand > mejor) mejor = cand;
                                }
                                if(k == 2 && c >= 1){
                                    int cand = dp[base - sC] + s;
                                    if(cand > mejor) mejor = cand;
                                }
                                if(k == 3 && d >= 1){
                                    int cand = dp[base - 1] + s;
                                    if(cand > mejor) mejor = cand;
                                }
                            }

                            dp[idx] = mejor;
                        }
                    }
                }
            }
        }
    }
    int resultado = dp[n*sI + W*sW + l0*sA + l1*sB + l2*sC + l3];
    delete[] dp;
    return resultado;
}



int main(){
    int n;
    int w;
    cin >> n >> w;
    
    int l0;
    int l1;
    int l2;
    int l3;
    cin >> l0 >> l1 >> l2 >> l3;

    int* peso = new int[n];
    int* sat = new int[n];
    int* cat = new int[n];

    for (int i = 0; i < n; i++){
        cin >> peso[i] >> sat[i] >> cat[i];
    }

    int resultado = maxSatisfaccion(n, w, l0, l1, l2, l3, peso, sat, cat);

    cout << resultado;
    delete[] peso;
    delete[] sat;
    delete[] cat;

    return 0; 
}

