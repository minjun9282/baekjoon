#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, F, result;
    int new_num;
    cin >> N >> F;
    
    new_num = (N / 100) * 100;
    if(new_num % F == 0){
        cout << "00" << '\n';
    }
    else{
        int i = 0;
        while(true){
            if((new_num + i) % F == 0){
                result = (new_num + i) % 100;
                if(result < 10){
                    cout << 0 << result << '\n';
                }
                else{
                    cout << result << '\n';
                }
                break;
            }
            i++;
        }
    }
    
    return 0;
}