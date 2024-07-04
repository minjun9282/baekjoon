#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int *arr = new int[N + 1];
    int *price = new int[N + 1];
    
    arr[0] = 0;
    for (int i = 1; i < N + 1; i++){
        cin >> arr[i];
    }
    
    price[0] = 0;
    for (int i = 1; i < N + 1; i++){
        for (int j = 1; j <= i; j++){
            price[i] = max(price[i], price[i-j] + arr[j]);
        }
    }
    cout << price[N] << '\n';
    
    delete[] arr;
    delete[] price;
    
    return 0;
}