#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int M = N;
    int* arr = new int[N];
    int i = 0;
    while(i < N){  
        cin >> arr[i];
        i++;
    }
    int min;
    int min_index;
    int result = 0;
    while(M > 0){
        min = arr[0];
        min_index = 0;
        for(int i = 1; i < N; i++){
            if(arr[i] <= min){
                min = arr[i];
                min_index = i;
            }
        }
        result += min * M;
        arr[min_index] = 1001;
        M--;
    }
    cout << result << '\n';

    delete[] arr;
    return 0;
}