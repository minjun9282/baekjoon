#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    while(N != 0){
        for(int i = 0; i < N; i++){
            cout << "*";
        }
        cout << '\n';
        N--;
    }
    
    return 0;
}