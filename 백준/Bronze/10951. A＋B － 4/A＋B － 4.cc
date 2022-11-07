#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B;
    while(true){
        cin >> A >> B;
        if (cin.eof()){
            break;
        }
        else{
            cout << A + B << '\n';
        }
    }
    
    return 0;
}