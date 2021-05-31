#include <iostream>
using namespace std;

// 분할정복으로 이항계수 구하기 -> 같은 사례를 중복 계산하는 경우 비효율적임.

int bin(int n, int k);

int main(){

    cout << "8 C 5 = " << bin(8, 5) << '\n';

    return 0;
}

int bin(int n, int k){
    if(k == 0 || n == k){
        return 1;
    }
    else{
        return bin(n-1, k-1) + bin(n-1, k);
    }
}