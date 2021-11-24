#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n, x_one, y_one, x_two, y_two, min_results = 0;
    float r_one, r_two;
    // 테스트 케이스의 개수, 출발점과 도착점 및 행성계의 개수 입력받기.
    cin >> T;
    
    int i = 0;
    while(i < T){
    cin >> x_one >> y_one >> x_two >> y_two;
    cin >> n;
    // 행성계의 중심의 좌표와 반지름의 길이를 저장하는 동적배열 생성
    int* c_x = new int[n];
    int* c_y = new int[n];
    int* r = new int[n];
    
    // 행성계의 중심의 좌표와 반지름의 길이 입력 받기
    for(int i = 0; i < n; i++){
        cin >> c_x[i] >> c_y[i] >> r[i];
        r_one = sqrt(pow((x_one-c_x[i]), 2) + pow((y_one-c_y[i]), 2));
        r_two = sqrt(pow((x_two-c_x[i]), 2) + pow((y_two-c_y[i]), 2));
        if((r_one < r[i]) && (r_two > r[i])){
            min_results++;
        }
        else if((r_one > r[i]) && (r_two < r[i])){
            min_results++;
        }
    }
    
    cout << min_results << '\n';

    delete[] c_x;
    delete[] c_y;
    delete[] r;

    i++;
    min_results = 0;
    }
    
    
    return 0;
}
