#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> soldiers(N);
    for (int i = 0; i < N; i++) {
        cin >> soldiers[i];
    }

    //arr[i]: i번째 병사까지 계산한 최대 병사 수
    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (soldiers[j] > soldiers[i]) {  // 감소하는 수열 조건
                dp[i] = max(dp[i], dp[j] + 1); //j번째 병사를 포함했을 때와 현재까지 계산된 최대 병사수 값을 비교
            }
        }
    }

    //최대 병사 수
    int max_num = *max_element(dp.begin(), dp.end());

    // 제거해야 하는 병사의 수 = 전체 병사 수 - 최대 병사 수
    cout << N - max_num << '\n';

    return 0;
}
