#include <iostream>
#include <cmath>
using namespace std;

//index h, m과 배열 U, V를 사용하지 않는 합병정렬

void mergesort2(int low, int high, int* S);
void merge2(int low, int mid, int high, int* S);

int main(){
    int arr[10] = {3, 2, 7, 8, 1, 4, 9, 6, 5, 10};
    mergesort2(0, 9, arr);
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}

void mergesort2(int low, int high, int* S){
    int mid;
    if(low < high){
        mid = floor((low + high) / 2);
        mergesort2(low, mid, S);
        mergesort2(mid + 1, high, S);
        merge2(low, mid, high, S);
    }
}

void merge2(int low, int mid, int high, int* S){
    int i, j, k;
    int U[high - low + 1];
    i = low; j = mid + 1; k = low;
    while(i <= mid && j <= high){
        if(S[i] < S[j]){
            U[k] = S[i];
            i++;
        }
        else{
            U[k] = S[j];
            j++;
        }
        k++;
    }
    if( i > mid){
        for(int l = j; l < high; l++){
            U[k] = S[l];
            k++;
        }
    }
    else{
        for(int l = i; l < mid; l++){
            U[k] = S[l];
            k++;
        }
    }
    for(int l = low; l < high; l++){
        S[l] = U[l];
    }
}