#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();

    // dp[i][j] = str1의 앞에서 i글자, str2의 앞에서 j글자를 사용했을 때의 LCS 길이
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i - 1] == str2[j - 1]) {
                // 두 문자가 같다면, 직전 (i-1, j-1) 상태 + 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // 두 문자가 다르면, 위쪽/왼쪽 중 더 큰 값
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << '\n';

    return 0;
}
