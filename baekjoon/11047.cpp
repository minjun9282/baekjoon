#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    int* arr = new int[N];
    int i = 0;
    while(i < N){
        cin >> arr[i];
        i++;
    }
    int num_c = 0;
    int j = N-1;
    while(K != 0){
        if(arr[j] <= K){
            num_c++;
            K = K - arr[j];
        }
        else{
            j--;
        }
    }
    cout << num_c << '\n';

    delete[] arr;
    return 0;
}