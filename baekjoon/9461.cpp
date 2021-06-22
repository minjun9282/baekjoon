#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;
    cin >> T;
    int i = 0;
    while(i < T){
        cin >> N;
        if(N < 4){
            cout << 1 << '\n';
        }
        else if((N > 3) && (N < 6)){
            cout << 2 << '\n';
        }
        else{
            long long int* arr = new long long int[N];
            arr[0] = 1; arr[1] = 1; arr[2] = 1;
            arr[3] = 2; arr[4] = 2;
            for(int i = 5; i < N; i++){
                arr[i] = arr[i - 1] + arr[i - 5];
            }
            cout << arr[N-1] << '\n';
            delete[] arr;
        }
        i++;
    }

    return 0;
}