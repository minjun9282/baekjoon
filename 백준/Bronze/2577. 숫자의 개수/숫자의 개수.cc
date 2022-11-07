#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, C, result, remainder;
    cin >> A;
    cin >> B;
    cin >> C;
    result = A * B * C;
    int digit[10];
    fill_n(digit, 10, 0);
    
    while(true){
        if(result < 10){
            remainder = result;
            digit[remainder]++;
            break;
        }
        else{
            remainder = result % 10;
            result = result / 10;
            digit[remainder]++;
        }
    }
    for(int i = 0; i < 10; i++){
        cout << digit[i] << '\n';
    }
    
    return 0;
}