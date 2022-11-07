#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int inca_cal(int M, int N, int x, int y, int lcm);

int main(){
    int T;
    int M, N, x, y, i = 0;
    cin >> T;
    while(i < T){
        cin >> M >> N >> x >> y;
        int lcm_MN = lcm(M, N);
        cout << inca_cal(M, N, x, y, lcm_MN) << '\n';
        i++;
    }

    return 0;
}

int inca_cal(int M, int N, int x, int y, int lcm){
    int answer;
    bool find = false;
    for(int i = 1; i < lcm + 1; i++){
        if(i % M == x && i % N == y){
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