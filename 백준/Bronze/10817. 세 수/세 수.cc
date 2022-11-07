#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 세 정수 A, B, C가 주어진다.
    int array[3];
    for(int i = 0; i < 3; i++){
        cin >> array[i];
    }

    int lowest, lowest_index;
    // 2. 세 정수를 비내림차순으로 정렬
    for(int i = 0; i < 3; i++){
        lowest = array[i];
        lowest_index = i;
        for(int j = i + 1; j < 3; j++){
            if ((array[j] < array[i])&&(array[j]< lowest)){
                lowest = array[j];
                lowest_index = j;
            }
        }
        array[lowest_index] = array[i];
        array[i] = lowest;
    }

    // 3. 두 번째로 큰 정수 출력
    cout << array[1] << '\n';
    
    return 0;
}