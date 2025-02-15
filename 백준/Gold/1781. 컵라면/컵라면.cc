#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<pair<int, int>> input(N);
    
    for (int i = 0; i < N; i++) {
        cin >> input[i].first >> input[i].second;
    }

    sort(input.begin(), input.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto [deadline, reward] : input) {
        pq.push(reward);
        if (pq.size() > deadline) {
            pq.pop(); // 가장 작은 값 제거
        }
    }

    int result = 0;
    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }

    cout << result << '\n';

    return 0;
}
