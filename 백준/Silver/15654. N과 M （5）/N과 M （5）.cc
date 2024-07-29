#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[10];
int c[10];
vector<int> v(10);

void go(int index, int n, int m){
    if (index == m){
        for (int i = 0; i < m; i++){
            cout << v[a[i]];
            if (i != m - 1){
                cout << " ";
            }
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++){
        if (c[i]){
            continue;
        }
        c[i] = true;
        a[index] = i;
        go(index+1, n, m);
        c[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    go(0, N, M);

    return 0;
}