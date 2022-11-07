#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int j = 0;
    while(N != 0){
        for(int i = 0; i < j; i++){
            cout << " ";
        }
        for(int i = 0; i < N; i++){
            cout << "*";
        }
        cout << '\n';
        N--;
        j++;
    }
    
    return 0;
}