#include <iostream>
#include <cmath>
using namespace std;

bool decline_num(long long int n);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, i = 0;
    cin >> N;
    
    long long int Nth_decline_num;
    int Nth = -1;
    while(true){
        if(decline_num(i) == true){
            Nth++;
            if(Nth == N){
                Nth_decline_num = i;
                break;
            }
        }
        i++;
    }
    cout << Nth_decline_num << '\n';

    return 0;
}

bool decline_num(long long int n){
    long long int cipher = floor(log10(n)) + 1;
    long long int temp, divisor, i = 1;
    bool decline = true;
    while(i < cipher){
        divisor = pow(10, cipher - i);
        temp = n / divisor;
        if(temp <= ((n % divisor) / (divisor / 10))){
            decline = false;
            break;
        }
        else{
            n = n % 10;
        }
        i++;
    }
    return decline;
}