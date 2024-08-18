#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int height[10001] = {0};
    for (int i = 0; i < M; i++){
        int num_1, num_2;
        cin >> num_1 >> num_2;
        height[num_1] = i+1;
        height[num_2] = i+1;
    }
    int arr[2001] = {0};
    int j = 1;
    for(int i = 0; i < 10001; i++){
        if (height[i] != 0){
            arr[j] = height[i];
            j++;
        }
    }
    if (N > 2 * M){
        int k = 1;
        while(k <= N){
            arr[k + 2 * M] = arr[k];
            k++;
        }
    }
    cout << arr[N] << '\n';
    
    return 0;
}