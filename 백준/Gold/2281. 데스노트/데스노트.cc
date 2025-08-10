#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> names(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> names[i];
    }

    vector<long long> ps(n + 1, 0);
    for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + names[i];

    vector<vector<long long>> width(n + 1, vector<long long>(n + 1, 0));
    for (int s = 1; s <= n; ++s) {
        for (int i = s; i <= n; ++i) {
            width[s][i] = (ps[i] - ps[s - 1]) + (i - s);
        }
    }

    const long long INF = 1e18;
    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, INF)); // dp[i][s]: s번째 이름으로 시작한 줄에 i번째까지 같은 줄로 썼을 때,

    if (names[1] <= m){
        dp[1][1] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int s = i; s >= 1; --s) {
            long long cur = dp[i][s];
            if (cur == INF){
                continue;
            }
            long long w = width[s][i];
            if (w > m){
                break;
            }
    
            if (i == n){
                continue;
            }
            if (w + 1 + names[i + 1] <= m){
                dp[i + 1][s] = min(dp[i + 1][s], cur);
            }
    
            long long rem = m - w;
            dp[i + 1][i + 1] = min(dp[i + 1][i + 1], cur + rem * rem);
        }
    }

    long long ans = INF;
    for (int s = 1; s <= n; ++s) {
        long long w = width[s][n];
        if (w <= m){
            ans = min(ans, dp[n][s]);
        }
    }

    cout << ans << "\n";
    return 0;
}
