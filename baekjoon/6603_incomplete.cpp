#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(False);
    cin.tie(NULL);
    int N, temp;
    while(true){
        cin >> N;
        if(N == 0){
            break;
        }
        else{
            int* arr = new int[N];
        }
        int j = 0;
        while(j < N){
            cin >> arr[j];
            j++; 
        }
        delete[] arr;
    }

    return 0;
}