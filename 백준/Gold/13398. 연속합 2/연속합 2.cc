#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp(n), remove(n);
    dp[0] = v[0];
    remove[0] = v[0];
    int max_sum = v[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(v[i], dp[i-1] + v[i]);
        remove[i] = max(dp[i-1], remove[i-1] + v[i]);
        max_sum = max({max_sum, dp[i], remove[i]});
    }

    cout << max_sum << '\n';
    return 0;
}
