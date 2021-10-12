#include <iostream>
#include <string>
using namespace std;

int main(){
    int K;
    string S;
    cin >> K;
    cin >> S;
    for(int i = 0; i < S.length(); i += K){
        cout << S[i];
    }
    cout << '\n';

    return 0;
}