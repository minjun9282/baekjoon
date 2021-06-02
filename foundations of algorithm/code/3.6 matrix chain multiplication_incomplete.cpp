#include <iostream>
using namespace std;

// 연쇄 행렬곱셈 알고리즘 : 연쇄 행렬 곱셈 시 곱셈의 총횟수가 가장 적은 방법을 찾는 알고리즘

int minmult(int n, const int d[], int M[][6], int P[][6]); // 예제의 행렬의 갯수가 6이여서 6으로 설정함.
                                                           // int M[n][n]; // 배열 M의 Mij의 값은 i < j일때 Ai부터 Aj까지 행렬을 곱하는데 필요한 원소단위 곱셈의 최소 휫수를 나타냄.

int main(){
    int d[7] = {5, 2, 3, 4, 6, 7, 8};
    int P[5][6];
    int M[6][6];
    minmult(6, d, M, P);
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6 - i; j++){
            cout << M[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}

int minmult(int n, const int d[], int M[][6], int P[][6]){
    int i, j, k, diagonal;
    int min_value;
    int min_index;
    
    for(i = 0; i < n; i++){
        M[i][i] = 0; // 
    }
    for(diagonal = 0; diagonal < n -1; diagonal++){
        for(i = 0; i < n - diagonal; i++){
            j = i + diagonal;
            min_value = M[i][i] + M[i + 1][j] + d[i - 1]*d[i]*d[j];
            min_index = i;
            for(k = i + 1; i < j; k++){
                if((M[i][k] + M[k + 1][j] + d[i - 1]*d[k]*d[j]) < min_value){
                    min_value = M[i][k] + M[k + 1][j] + d[i - 1]*d[k]*d[j];
                    min_index = k;
                }
            }
            M[i][j] = min_value;
            P[i][j] = min_index;
        }
    }
    return M[0][n-1];
}