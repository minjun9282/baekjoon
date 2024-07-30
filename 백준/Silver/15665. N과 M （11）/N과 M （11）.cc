#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int a[10];
vector<int> v;

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
        a[index] = i;
        go(index + 1, n, m);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    set<int> no_dup;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        no_dup.insert(num);
    }
    v.resize(no_dup.size());
    v.assign(no_dup.begin(), no_dup.end());
    sort(v.begin(), v.end());
    go(0, v.size(), M);
    
    return 0;
}