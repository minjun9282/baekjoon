#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int a[10];
vector<int> v;
void go(int index, int start, int n, int m){
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
    for (int i = start; i < n; i++){
        a[index] = i;
        go(index + 1, i, n, m);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    set<int> s;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        s.insert(num);
    }
    v.assign(s.begin(), s.end());
    sort(v.begin(), v.end());
    go(0, 0, v.size(), M);
    
    return 0;
}