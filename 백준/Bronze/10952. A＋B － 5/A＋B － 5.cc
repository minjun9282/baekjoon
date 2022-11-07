#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B;
    while(true){
        cin >> A >> B;
        if ((A == 0) && (B == 0))
            break;
        else{
            cout << A + B << endl;
        }
        
    }
    
    return 0;
}