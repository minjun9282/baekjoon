#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    char arr[N][N];
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int num_mobis = 0;

    // 가로 방향 검사
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= N - 5; j++){
            if (arr[i][j] == 'M' && arr[i][j+1] == 'O' && arr[i][j+2] == 'B' && arr[i][j+3] == 'I' && arr[i][j+4] == 'S'){
                num_mobis += 1;
            }
            if (arr[i][j] == 'S' && arr[i][j+1] == 'I' && arr[i][j+2] == 'B' && arr[i][j+3] == 'O' && arr[i][j+4] == 'M'){
                num_mobis += 1;
            }
        }
    }

    // 세로 방향 검사
    for (int i = 0; i <= N - 5; i++){
        for (int j = 0; j < N; j++){
            if (arr[i][j] == 'M' && arr[i+1][j] == 'O' && arr[i+2][j] == 'B' && arr[i+3][j] == 'I' && arr[i+4][j] == 'S'){
                num_mobis += 1;
            }
            if (arr[i][j] == 'S' && arr[i+1][j] == 'I' && arr[i+2][j] == 'B' && arr[i+3][j] == 'O' && arr[i+4][j] == 'M'){
                num_mobis += 1;
            }
        }
    }

    // 대각선 방향 검사
    for (int i = 0; i <= N - 5; i++){
        for (int j = 0; j <= N - 5; j++){
            if (arr[i][j] == 'M' && arr[i+1][j+1] == 'O' && arr[i+2][j+2] == 'B' && arr[i+3][j+3] == 'I' && arr[i+4][j+4] == 'S'){
                num_mobis += 1;
            }
            if (arr[i][j] == 'S' && arr[i+1][j+1] == 'I' && arr[i+2][j+2] == 'B' && arr[i+3][j+3] == 'O' && arr[i+4][j+4] == 'M'){
                num_mobis += 1;
            }
            if (arr[i+4][j] == 'M' && arr[i+3][j+1] == 'O' && arr[i+2][j+2] == 'B' && arr[i+1][j+3] == 'I' && arr[i][j+4] == 'S'){
                num_mobis += 1;
            }
            if (arr[i+4][j] == 'S' && arr[i+3][j+1] == 'I' && arr[i+2][j+2] == 'B' && arr[i+1][j+3] == 'O' && arr[i][j+4] == 'M'){
                num_mobis += 1;
            }
        }
    }

    cout << num_mobis << '\n';
    
    return 0;
}
