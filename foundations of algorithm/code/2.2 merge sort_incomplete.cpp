#include <iostream>
#include <cmath>
using namespace std;

// n개의 원소를 비내림차순으로 정렬

void mergesort(int n, int S[]);
void merge(int h, int m, const int U[], const int V[], int* S);

int main(){
    int arr[10] = {5, 7, 2, 3, 8, 9, 11, 16, 23, 22};
    mergesort(10, arr);
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}

void mergesort(int n, int S[]){
    if(n > 0){
        const int h = floor(n / 2);
        const int m = n - h;
        int* U = new int[h];
        int* V = new int[m];
        for(int i = 0; i < h; i++){
            U[i] = S[i];
        }
        for(int j = 0; j < m - h; j++){
            V[j] = S[h + j];
        }
        mergesort(h, U);
        mergesort(m, V);
        merge(h, m, U, V, S);
    }
}

void merge(int h, int m, const int U[], const int V[], int* S){
    int i, j, k;
    i = 0; j = 0; k = 0;
    while(i < h && j < m){
        if(U[i] < V[j]){
            S[k] = U[i];
            i++;
        }
        else{
            S[k] = V[j];
            j++;
        }
        k++;
    }
    if(i > h){
        for(int l = j; l < m; l++){
            S[k] = V[l];
            k++;
        }
    }
    else{
        for(int l = i; l < h; i++){
            S[k] = U[i];
            i++;
        }
    }
}