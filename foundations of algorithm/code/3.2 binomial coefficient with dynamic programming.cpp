#include <iostream>
#include <cmath>
using namespace std;

int bin2(int n, int k);

int main(){
    cout << "8 C 5 = " << bin2(8, 5) << '\n';

    return 0;
}

int bin2(int n, int k){
    int i, j;
    int B[n+1][k+1];
    for(i = 0; i < n + 1; i++){
        for(j = 0; j < min(i, k) + 1; j++){
            if(j == 0 || j == i){
                B[i][j] = 1;
            }
            else{
                B[i][j] = B[i-1][j-1] + B[i-1][j];
            }
        }
    }
    return B[n][k];
}