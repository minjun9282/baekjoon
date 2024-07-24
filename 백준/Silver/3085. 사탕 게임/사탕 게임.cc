#include <iostream>
#include <vector>
using namespace std;

int cal_max(const vector<vector<char>>& arr, int size){
    int max_num = 0;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            int num = 1;
            char now = arr[i][j];
            int k = j + 1;
            while (k < size){
                if (arr[i][k] == now){
                    num += 1;
                } else{
                    break;
                }
                k++;
            }
            if (num > max_num){
                max_num = num;
            }
        }
    }

    for (int j = 0; j < size; j++){
        for (int i = 0; i < size - 1; i++){
            int num = 1;
            char now = arr[i][j];
            int k = i + 1;
            while (k < size){
                if (arr[k][j] == now){
                    num += 1;
                } else {
                    break;
                }
                k++;
            }
            if (num > max_num){
                max_num = num;
            }
        }
    }

    return max_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<char>> arr(N, vector<char>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    int max_num = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - 1; j++){
            if (arr[i][j] != arr[i][j + 1]){
                swap(arr[i][j], arr[i][j + 1]);
                int temp_max = cal_max(arr, N);
                if (temp_max > max_num){
                    max_num = temp_max;
                }
                swap(arr[i][j], arr[i][j + 1]); 
            }
        }
    }

    for (int j = 0; j < N; j++){
        for (int i = 0; i < N - 1; i++){
            if (arr[i][j] != arr[i + 1][j]){
                swap(arr[i][j], arr[i + 1][j]);
                int temp_max = cal_max(arr, N);
                if (temp_max > max_num){
                    max_num = temp_max;
                }
                swap(arr[i][j], arr[i + 1][j]); 
            }
        }
    }
    
    cout << max_num << '\n';

    return 0;
}
