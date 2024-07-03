#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[1000001] = {false};
    for (int i = 2; i < 1000001; i++){
        if (arr[i] == false){
            for (int j = i * 2; j < 1000001; j += i){
                arr[j] = true;
            }
        }
    }
    
    while (true){
        int num;
        cin >> num;
        if (num == 0){
            break;
        }
        else{
            int k = 2;
            bool conjecture = false;
            while (k <= (num / 2)){
                if (arr[k] == false && arr[num-k] == false){
                    cout << num << " = " << k << " + " << num - k << '\n';
                    conjecture = true;
                    break;
                }
                k++;
            }
            if (conjecture == false){
                cout << "Goldbach's conjecture is wrong." << '\n';
            }
        }
    }
    
    return 0;
}