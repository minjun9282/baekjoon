#include <iostream>
using namespace std;

// 피보나치 수열에서 n번째 숫자를 찾으시오.
// 피보나치 수열의 첫번째 항을 1이라고 가정함.

int fib(int n);

int main(){

    cout << fib(8) << '\n';

    return 0;
}

int fib(int n){
    int* arr = new int[n+1];
    int result;

    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i < n+1; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    result = arr[n];
    delete[] arr;
    return result;
}