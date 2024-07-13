#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100001][2];
long long score[100001][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> arr[i][0];
        }
        for (int i=1; i<=n; i++) {
            cin >> arr[i][1];
        }
        score[0][0] = score[0][1] = score[0][2] = 0;
        for (int i=1; i<=n; i++) {
            score[i][0] = max({score[i-1][0],score[i-1][1],score[i-1][2]});
            score[i][1] = max(score[i-1][0],score[i-1][2])+arr[i][0];
            score[i][2] = max(score[i-1][0],score[i-1][1])+arr[i][1];
        }
        long long ans = max({score[n][0], score[n][1], score[n][2]});
        cout << ans << '\n';
    }
    return 0;
}