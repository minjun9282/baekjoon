#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char input;
    cin >> input;
    if(input == 'N' || input == 'n'){
        cout << "Naver D2" << '\n';
    }
    else{
        cout << "Naver Whale" << '\n';
    }

    return 0;
}