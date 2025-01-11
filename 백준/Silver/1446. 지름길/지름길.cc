#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, D;
    cin >> N >> D;
    // 딱 맞춰서 도착해야 함.
    // dp[i] = min(dp[i-1]+1, dp[i-2]+2, ..., dp[0] + i); cf) dp[0]+i가 사실상 i.
    vector<int> dp(D+1);
    for (int i = 0; i < D+1; i++){
        dp[i] = i;
    }
    vector<tuple<int, int, int>> shortcuts;
    while(N--){
        int start, end, length;
        cin >> start >> end >> length;
        if (end <= D){
            shortcuts.push_back({start, end, length});
        }
    }
    
    for(int i = 0; i < D+1; i++){
        if (i > 0){
            dp[i] = min(dp[i], dp[i-1] + 1);
        }
        for (auto &sc : shortcuts) {
            int start = get<0>(sc);
            int end = get<1>(sc);
            int length = get<2>(sc);
            if (i == start) {
                dp[end] = min(dp[end], dp[i] + length);
            }
        }

    }
    cout << dp[D] << '\n';
    
    return 0;
}