#include <iostream>
using namespace std;

int find_third(int arr[]);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    int j = 0;
    int arr[10];
    while(j < T){
        for(int i = 0; i < 10; i++){
            cin >> arr[i];
        }
        cout << find_third(arr) << '\n';
        j++;
    }

    return 0;
}

int find_third(int arr[]){
    int first, second, third;
    int first_idx, second_idx, third_idx;
    first = 0;
    for(int i = 0; i < 10; i++){
        if(arr[i] > first){
            first = arr[i];
        }
    }
  
    second = 0;
    for(int i = 0; i < 10; i++){
        if(arr[i] > second && first > arr[i]){
            second = arr[i];
        }
    }

    third = 0;
    for(int i = 0; i < 10; i++){
        if(arr[i] > third && second > arr[i]){
            third = arr[i];
        }
    }

    return third;
}