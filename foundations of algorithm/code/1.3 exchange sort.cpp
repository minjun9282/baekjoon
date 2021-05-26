#include <iostream>
using namespace std;

// 비내림차순으로 n개의 키를 정렬하기
    // cf)비내림차순: 중복되는 원소가 있는 오름차순

void exchange(int n, int S[]);

int main(){
    int S[] = {5, 2, 6, 8, 3, 8, 9, 1, 7, 2, 10, 6};
    // 정렬하기 전 배열 S의 원소 출력
    for(int i = 0; i < 12; i++){
        cout << S[i] << " ";
    }
    cout << '\n';
    // 정렬 후 배열 S의 원소 출력
    exchange(12, S);
    for(int i = 0; i < 12; i++){
        cout << S[i] << " ";
    }

    return 0;
}

void exchange(int n, int S[]){
    int index_i, index_j;
    int temp;
    for(index_i = 0; index_i < n - 1; index_i++){
        for(index_j = index_i + 1; index_j < n; index_j++){
            if(S[index_i] > S[index_j]){
                temp = S[index_j];
                S[index_j] = S[index_i];
                S[index_i] = temp;
            }
        }
    }
}