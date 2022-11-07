#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int inca_cal(int M, int N, int x, int y, long long int lcm);

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
    for(long long int i = 0; i * M + x < lcm + 1; i++){
        if( (i * M + x - 1) % N  + 1== y ){
            find = true;
            answer = i * M + x;
        }
    }
    if(find == true){
        return answer;
    }
    else{
        return -1;
    }
}