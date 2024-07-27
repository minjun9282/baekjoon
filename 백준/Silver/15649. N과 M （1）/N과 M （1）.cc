#include <iostream>
#include <vector>
using namespace std;

bool c[10];
int a[10];

void go(int index, int n, int m){
    if (index == m){
        for (int i = 0; i < m; i++){
            cout << a[i];
            if (i != m - 1){
                cout << " ";
            }
        } 
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= n; i++){
        if (c[i]){
            continue;
        }
        c[i] = true;
        a[index] = i;
        go(index + 1, n, m);
        c[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    go(0, N, M);
    
    return 0;
}