#include <iostream>
#include <vector>
using namespace std;

int max_profit = 0;
vector<int> T;
vector<int> P;

void go(int index, int N, int sum) {
    if (index >= N) {
        if (sum > max_profit) {
            max_profit = sum;
        }
        return;
    }
    
    if (index + T[index] <= N) {
        go(index + T[index], N, sum + P[index]);
    }
    go(index + 1, N, sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    T.resize(N);
    P.resize(N);
    for(int i = 0; i < N; i++){
        cin >> T[i] >> P[i];
    }
    go(0, N, 0);
    cout << max_profit << '\n';
    
    
    return 0;
}