#include <iostream>
using namespace std;

// quick sort는 분할한 배열을 재귀 호출로 정렬하여 합병한다는 점에서 합병정렬과 비슷함.
// 하지만 quick sort는 분할의 기준이 pivot point라는 점에서 기본적인 합병정렬과는 다름.

void quicksort(int low, int high, int* S);
void partition(int low, int high, int& pivotpoint), int* S;

int main(){

    return 0;
}

void quicksort(int low, int high, int* S){
    int pivotpoint; // quicksort의 핵심은 pivot 기준으로 왼쪽에는 pivot보다 작은 수, 오른쪽에는 pivot보다 큰 수를 두는 것. 나열 순서는 상관 없음.
    if(low < high){
        partition(low, high, pivotpoint, S);
        quicksort(low, pivotpoint - 1, int* 분할되어 생긴 앞의 arr);
        quicksort(pivotpoint + 1, high, 새로 생긴 pivot보다 큰 arr);
    }
}

void partition(int low, int high, int& pivotpoint, int* S){
    int i, j;
    int temp;
    int pivotitem;
    pivotitem = S[low];
    j = low;
    for(i = low + 1; i < high; i++){
        if(S[i] < pivotitem){
            j++;
            temp = S[i];
            S[i] = S[j];
            S[j] = temp;
        }
    }
    pivotpoint = j;
    temp = S[pivotpoint];
    S[pivotpoint] = S[low];
    S[low] = temp;
}