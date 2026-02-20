#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    stack<pair<int, int>> s;

    for (int i = 1; i <= N; i++) {
        int current_height;
        cin >> current_height;

        while (!s.empty() && s.top().first < current_height) {
            s.pop();
        }

        if (s.empty()) {
            cout << "0 ";
        }
        else {
            cout << s.top().second << " ";
        }
        s.push({ current_height, i });
    }

    cout << '\n';
    return 0;
}