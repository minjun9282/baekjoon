#include <iostream>
using namespace std;

// 수가 n개 있는 배열 S에 있는 수 모두 더하기

int sum(int n, const int S[]);

int main(){
    int S[10] = {4, 7, 3, 2, 8, 9, 1, 6, 10, 5};
    cout << sum(10, S) << '\n';

    return 0;
}

int sum(int n, const int S[]){
    int result = 0;
    for(int i = 0; i < n; i++){
        result += S[i];
    }
    return result;
}