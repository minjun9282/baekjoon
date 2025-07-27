#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    // 어떤 수 X를 최대 1개 사용 -> 어떤 수 X를 1개 사용 경우의 수 + 어떤 수 X를 0개 사용 경우의 수
    // = k-X를 표현하는 경우의수 + k를 표현하는 경우의 수
    
    vector<int> dp(k + 1, 0); // dp[i] : 합이 i가 되는 경우의 수를 저장하는 배열임.
    dp[0] = 1;  // 합이 0이 되는 경우는 없음.

    for (int x : num) {
        for (int j = x; j <= k; j++) {
            dp[j] += dp[j - x];
        }
    }

    cout << dp[k] << "\n";
    
    return 0;
}