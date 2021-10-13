#include <iostream>
#include <cmath>
using namespace std;

unsigned long long binary_arth(int n); //배열을 반환하는 함수로 수정하기

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    unsigned long long int result;
    cin >> N >> K;
    result = binary_arth(1000000); //result에 포함된 1의 갯수와 K를 비교하여 몇개의 물병이 필요한지 계산하기
    cout << result << '\n';
    
    return 0;
}

unsigned long long binary_arth(int n){
    int temp = n;
    int rem;
    unsigned long long bin_result = 0;
    int i = 0;
    while(temp > 0){
        rem = temp % 2;
        temp = temp / 2;
        bin_result += rem * pow(10, i);
        i++;
    }
    return bin_result;
}
