#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int inca_cal(int M, int N, int x, int y, long long int lcm); // 최소 공배수가 매우 클 수 있어서 long long int를 사용함.

int main(){
    int T;
    int M, N, x, y, i = 0;
    cin >> T;
    while(i < T){
        cin >> M >> N >> x >> y;
        long long int lcm_MN = lcm(M, N);
        cout << inca_cal(M, N, x, y, lcm_MN) << '\n';
        i++;
    }

    return 0;
}

int inca_cal(int M, int N, int x, int y, long long int lcm){
    long long int answer;
    bool find = false;
    for(long long int i = 1; i < lcm + 1; i++){ //반복되는 횟수가 너무 많아질 수 있으므로 i를 한쪽에 고정시켜서 생각함.
        if((i * M + x - 1) % N  + 1 == y){ // (i * M + x) % N == y로 할 경우 y와 N이 같을 때 나머지가 y가 아닌 0 이어서 오류가 발생 ex) 1 2 1 2 입력시 -1이 아닌 2가 답.
            find = true;
            answer = i;
        }
    }
    if(find == true){
        return answer;
    }
    else{
        return -1;
    }
}
