#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, N;
    cin >> M >> N;
    
    bool arr[1000001] = {false}; 
    
    for (int i = 2; i < 1000001; i++){
        if (arr[i] == false){ 
            for (int j = i * 2; j < 1000001; j += i){
                arr[j] = true; 
            }
        }
    }
    
    for (int k = M; k <= N; k++){
        if (k >= 2 && arr[k] == false){
            cout << k << '\n';
        }
    }
    
    return 0;
}
