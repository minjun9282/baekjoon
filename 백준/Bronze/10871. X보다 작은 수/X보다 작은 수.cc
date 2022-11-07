#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, X, item;
    cin >> N >> X;
    int *arr = new int[N];
    for(int i = 0; i < N; i++){
        cin >> item;
        arr[i] = item;
    }
    for (int i = 0; i < N; i++){
        if (arr[i] < X){
            cout << arr[i] << " ";
        }
    }
    delete[] arr;
    return 0;
}