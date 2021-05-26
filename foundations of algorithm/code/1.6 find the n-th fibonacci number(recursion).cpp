#include <iostream>
using namespace std;

// 피보나치 수열에서 n번째 수를 구하시오.
// 피보나치 수열의 첫번째 항이 1이라고 가정함.


int fib(int n);

int main(){
    
    cout << fib(8) << '\n';

    return 0;
}


int fib(int n){
    if(n <= 1){
        return n;
    }
    else{
        return fib(n-1) + fib(n -2);
    }
}