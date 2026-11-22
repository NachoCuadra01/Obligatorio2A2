#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

//FLOOR ACLARAR QUE LO DIO GPT
int memo[1001][1002][2];

int maxLikesMemo(int k, int ronda, int dif, int prev, int* pateadores, int* likes){
    if(ronda == k) return 0;
    if(memo[ronda][dif][prev] >= 0) return memo[ronda][dif][prev];

    int d1 = dif + pateadores[ronda];
    int mejor = maxLikesMemo(k, ronda + 1, d1, 0, pateadores, likes);

    if(d1 - 1 >= 0){
        int ganancia = likes[ronda];
        if(prev == 1) ganancia = floor(likes[ronda] / 2);
        int bailo = ganancia + maxLikesMemo(k, ronda + 1, d1 - 1, 1, pateadores, likes);
        if(bailo > mejor) mejor = bailo;
    }

    memo[ronda][dif][prev] = mejor;
    return mejor;
}

int maxLikes(int k, int* pateadores, int* likes){
    for(int r = 0; r < k; r++){
        for(int d = 0; d <= k; d++){
            memo[r][d][0] = -1;
            memo[r][d][1] = -1;
        }
    }
    return maxLikesMemo(k, 0, 0, 0, pateadores, likes);
}

int main(){
    int k;
    cin >> k;

    int* pateadores = new int[k];
    int* likes = new int[k];

    for(int i = 0; i < k; i++) {
        cin >> pateadores[i];
    }
    for(int i = 0; i < k; i++){
        cin >> likes[i];
    }    
    cout << maxLikes(k, pateadores, likes);

    delete[] pateadores;
    delete[] likes;
    return 0;
}