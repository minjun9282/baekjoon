#include <iostream>
#include <cmath>
using namespace std;

//플로이드 최단경로 알고리즘: 가중치포함 그래프의 각 마디에서 다른 모든 마디로 가는 최단 경로를 모두 계산하시오.
//  cf) 그래프의 경우 2차원 행렬을 활용하여 주어지는 것으로 가정함.

void floyd(int n, const int W[][5], int D[][5]); // 2차원 배열을 함수의 입력 파라메타로 넘겨주고자 할때에는 
                                                 // 함수가 넘겨받은 변수 자체로부터 배열 차원들을 알아낼 수 있는 방법으로 전달해야함.
                                                 // 출처 : https://skmagic.tistory.com/67

int main(){
    int n = 5; // 교재 그림 3.3을 활용하여 v1~v5까지 나온 그래프를 활용함.
    int graph[5][5]; // vn의 index는 모두 (index-1)이 됨. i - > j로 가는 가중치 그래프임. 이음선이 없으면 가중치를 100로 둠.
                     // 이음선이 없을 경우 무한과 같이 큰 수를 주면 되는데 여기서는 100정도면 다른 가중치에비해 충분히 커서 임의로 정함.
    int D[5][5];                                  
    graph[0][0] = 0; graph[0][1] = 1; graph[0][2] = 100; graph[0][3] = 1; graph[0][4] = 5;
    graph[1][0] = 9; graph[1][1] = 0; graph[1][2] = 3; graph[1][3] = 2; graph[1][4] = 100;
    graph[2][0] = 100; graph[2][1] = 100; graph[2][2] = 0; graph[2][3] = 4; graph[2][4] = 100;
    graph[3][0] = 100; graph[3][1] = 100; graph[3][2] = 2; graph[3][3] = 0; graph[3][4] = 3;
    graph[4][0] = 3; graph[4][1] = 100; graph[4][2] = 100; graph[4][3] = 100; graph[4][4] = 0;

    floyd(n, graph, D);

    cout << "그래프를 활용하여 구한 최단경로의 길이" << "\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << D[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}

void floyd(int n, const int W[][5], int D[][5]){
    int i, j, k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            D[i][j] = W[i][j];
        }
    }
    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}