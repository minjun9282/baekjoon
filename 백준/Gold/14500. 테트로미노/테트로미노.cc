#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> paper(N, vector<int>(M));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> paper[i][j];
        }
    }
    
    int max = 0;

    // 가로 일자
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= M - 4; j++){  // <= M - 4
            int temp = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i][j+3];
            if (temp > max){
                max = temp;
            }
        }
    }

    // 세로 일자
    for (int j = 0; j < M; j++){
        for (int i = 0; i <= N - 4; i++){  // <= N - 4
            int temp = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+3][j];
            if (temp > max){
            max = temp;
            }
        }
    }

    // 정사각형
    for (int i = 0; i <= N - 2; i++){  // <= N - 2
        for (int j = 0; j <= M - 2; j++){  // <= M - 2
            int temp = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1];
            if (temp > max){
                max = temp;
            }
        }
    }

    // ㄴ자 및 그 변형
    for (int i = 0; i <= N - 3; i++){  // <= N - 3
        for (int j = 0; j <= M - 2; j++){  // <= M - 2
            int temp = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+2][j+1];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 3; i++){  // <= N - 3
        for (int j = 0; j <= M - 2; j++){  // <= M - 2
            int temp = paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1] + paper[i+2][j];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 3; i++){  // <= N - 3
        for (int j = 0; j <= M - 2; j++){  // <= M - 2
            int temp = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+2][j];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 3; i++){  // <= N - 3
        for (int j = 0; j <= M - 2; j++){  // <= M - 2
            int temp = paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 2; i++){  // <= N - 2
        for (int j = 0; j <= M - 3; j++){  // <= M - 3
            int temp = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 2; i++){  // <= N - 2
        for (int j = 0; j <= M - 3; j++){  // <= M - 3
            int temp = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+2];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 2; i++){  // <= N - 2
        for (int j = 0; j <= M - 3; j++){  // <= M - 3
            int temp = paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 2; i++){  // <= N - 2
        for (int j = 0; j <= M - 3; j++){  // <= M - 3
            int temp = paper[i][j+2] + paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2];
            if (temp > max){
                max = temp;
            }
        }
    }

    // 볼록 철 모양
    for (int i = 0; i <= N - 2; i++){  // <= N - 2
        for (int j = 0; j <= M - 3; j++){  // <= M - 3
            int temp = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+1];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 2; i++){  // <= N - 2
        for (int j = 0; j <= M - 3; j++){  // <= M - 3
            int temp = paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2] + paper[i][j+1];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 3; i++){  // <= N - 3
        for (int j = 0; j <= M - 2; j++){  // <= M - 2
            int temp = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+1][j+1];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 3; i++){  // <= N - 3
        for (int j = 0; j <= M - 2; j++){  // <= M - 2
            int temp = paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1] + paper[i+1][j];
            if (temp > max){
                max = temp;
            }
        }
    }

    // 뱀 모양
    for (int i = 0; i <= N - 3; i++){  // <= N - 3
        for (int j = 0; j <= M - 2; j++){  // <= M - 2
            int temp = paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+2][j+1];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 3; i++){  // <= N - 3
        for (int j = 0; j <= M - 2; j++){  // <= M - 2
            int temp = paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1] + paper[i+2][j];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 2; i++){  // <= N - 2
        for (int j = 0; j <= M - 3; j++){  // <= M - 3
            int temp = paper[i][j+1] + paper[i][j+2] + paper[i+1][j] + paper[i+1][j+1];
            if (temp > max){
                max = temp;
            }
        }
    }
    for (int i = 0; i <= N - 2; i++){  // <= N - 2
        for (int j = 0; j <= M - 3; j++){  // <= M - 3
            int temp = paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+1][j+2];
            if (temp > max){
                max = temp;
            }
        }
    }

    cout << max << '\n';
    
    return 0;
}
