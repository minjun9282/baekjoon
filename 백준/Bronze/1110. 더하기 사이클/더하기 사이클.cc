#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, new_int;
    int cycle = 0;
    cin >> N;
    
    if (N < 10){
        new_int = N * 11;
    }
    else{
        new_int = (N % 10) * 10 + (((N / 10) + (N % 10)) % 10); 
    }
    cycle++;
    
    while(true){
        if (new_int == N){
            break;
        }
        else{
            if (new_int < 10){
                new_int = new_int * 11;
            }
            else{
                new_int = (new_int % 10) * 10 + (((new_int / 10) + (new_int % 10)) % 10);
            }
            cycle++;
        }
        
    }
    cout << cycle << endl;
    
    return 0;
}