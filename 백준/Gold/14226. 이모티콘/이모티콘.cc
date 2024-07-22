#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int S;
    cin >> S;

    vector<vector<int>> time(1001, vector<int>(1001, -1));
    queue<pair<int, int>> q;

    q.push({1, 0});
    time[1][0] = 0;

    while (!q.empty()) {
        int screen, clipboard;
        tie(screen, clipboard) = q.front();
        q.pop();

        if (screen == S) {
            cout << time[screen][clipboard] << '\n';
            return 0;
        }
        if (time[screen][screen] == -1) {
            time[screen][screen] = time[screen][clipboard] + 1;
            q.push({screen, screen});
        }
        if (clipboard > 0 && screen + clipboard <= 1000 && time[screen + clipboard][clipboard] == -1) {
            time[screen + clipboard][clipboard] = time[screen][clipboard] + 1;
            q.push({screen + clipboard, clipboard});
        }
        if (screen > 1 && time[screen - 1][clipboard] == -1) {
            time[screen - 1][clipboard] = time[screen][clipboard] + 1;
            q.push({screen - 1, clipboard});
        }
    }

    return 0;
}
