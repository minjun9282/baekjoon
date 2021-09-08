#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // 1. 배열 할당 및 도시간 거리, 기름 가격 데이터 입력받기
    int N;
    long long int min_costs = 0;
    long long int temp_costs;
    cin >> N;
    long long int* distance = new long long int[N-1];
    long long int* oil_price = new long long int[N];

    for(int i = 0; i < N-1; i++){
        cin >> distance[i];
    }
    for(int i = 0; i < N; i++){
        cin >> oil_price[i];
    }
    // 2. 최소 비용 계산
    long long int temp_price = oil_price[0];
    min_costs += temp_price * distance[0];
    for(int i = 1; i < N-1; i++){
        if(oil_price[i] < temp_price){
            temp_price = oil_price[i];
        }
        min_costs += temp_price * distance[i];
    }

    //3. 결과 출력 및 동적배열 할당 해제
    cout << min_costs << '\n';

    delete[] distance;
    delete[] oil_price;

    return 0;
}