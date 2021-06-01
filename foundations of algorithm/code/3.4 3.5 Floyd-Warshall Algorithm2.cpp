#include <iostream>
using namespace std;

//floyd alogritm인데 최단 경로의 길이가 아닌 최단 경로를 구성하는 vertex(마디)를 출력
void floyd2(int n, const int W[][5], int D[][5], int P[][5]); // 배열 P는 vi에서 vj까지 가는 최단 경로의 중간에 놓여있는 
                                                              // 마디가 한개 이상인 경우 그 중간에 놓여있는 마디들 중 가장 큰 인덱스
void path(int q, int r, int P[][5]);

int main(){
    int n = 5; // 교재 그림 3.3을 활용하여 v1~v5까지 나온 그래프를 활용함.
    int graph[5][5]; // vn의 index는 모두 (index-1)이 됨. i - > j로 가는 가중치 그래프임. 이음선이 없으면 가중치를 100로 둠.
                     // 이음선이 없을 경우 무한과 같이 큰 수를 주면 되는데 여기서는 100정도면 다른 가중치에비해 충분히 커서 임의로 정함.
    int D[5][5];
    int P[5][5];                               
    graph[0][0] = 0; graph[0][1] = 1; graph[0][2] = 100; graph[0][3] = 1; graph[0][4] = 5;
    graph[1][0] = 9; graph[1][1] = 0; graph[1][2] = 3; graph[1][3] = 2; graph[1][4] = 100;
    graph[2][0] = 100; graph[2][1] = 100; graph[2][2] = 0; graph[2][3] = 4; graph[2][4] = 100;
    graph[3][0] = 100; graph[3][1] = 100; graph[3][2] = 2; graph[3][3] = 0; graph[3][4] = 3;
    graph[4][0] = 3; graph[4][1] = 100; graph[4][2] = 100; graph[4][3] = 100; graph[4][4] = 0;

    floyd2(n, graph, D, P);
    cout << "배열 D 출력" << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << D[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    cout << "배열 P 출력" << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << P[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    cout << "v5 -> v3로 가는 최단경로 상에 있는 vertices" << '\n';
    path(4, 2, P);

    return 0;
}

void floyd2(int n, const int W[][5], int D[][5], int P[][5]){
    int i, j, k;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            P[i][j] = 0;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            D[i][j] = W[i][j];
        }
    }
    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if((D[i][k] + D[k][j]) < D[i][j]){
                    P[i][j] = k; // 여기서도 index가 (index - 1)된 것.
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

void path(int q, int r, int P[][5]){
    if(P[q][r] != 0){
        path(q, P[q][r], P);
        cout << "v" << P[q][r] << '\n';
        path(P[q][r], r, P);
    }
}
