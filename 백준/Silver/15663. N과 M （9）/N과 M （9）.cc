#include <iostream>
#include <vector>
#include <algorithm>
#include <set> 
using namespace std;

int a[10];
bool c[10];
vector<int> v;
set<vector<int>> uniqueSet;

void go(int index, int n, int m) {
    if (index == m) {
        vector<int> current;
        for (int i = 0; i < m; i++) {
            current.push_back(v[a[i]]);
        }
        uniqueSet.insert(current);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (c[i]) {
            continue;
        }
        c[i] = true;
        a[index] = i;
        go(index + 1, n, m);
        c[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    go(0, N, M);
    
    for (set<vector<int>>::iterator it = uniqueSet.begin(); it != uniqueSet.end(); ++it) {
        for (int j = 0; j < M; j++) {
            cout << (*it)[j];
            if (j != M - 1) {
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
