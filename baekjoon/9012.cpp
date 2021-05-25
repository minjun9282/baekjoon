#include <iostream>
#include <string>
using namespace std;

bool VPS(string input);

int main(){
    int T;
    string input;
    for(int i = 0; i < T; i++){
        cin >> input;
        VPS(input);
    }


    return 0;
}

bool VPS(string input){
    bool result;

    if(result == true){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }
}