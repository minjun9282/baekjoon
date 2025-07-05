#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

const int MAX_DIST = 1000;

bool isReachable(pair<int, int> from, pair<int, int> to) {
    int distance = abs(from.first-to.first) + abs(from.second -to.second);
    if (distance <= 1000){
        return true;
    }
    else{
        return false;
    }
}

bool bfs(vector<pair<int, int>>& coords) {
    int n = coords.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == n - 1){
            return true;
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && isReachable(coords[cur], coords[i])) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> coords(n + 2);

        for (int i = 0; i < n + 2; ++i) {
            cin >> coords[i].first >> coords[i].second;
        }

        if (bfs(coords)){
            cout << "happy" << '\n';
        }
        else{
            cout << "sad" << '\n';
        }
    }

    return 0;
}
