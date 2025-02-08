#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> staff;
vector<long long> result;

void dfs(int i) {
    for (int next : staff[i]) {
        result[next] += result[i];
        dfs(next);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    staff.resize(n + 1);
    result.resize(n + 1, 0);
    
    vector<int> sup_num(n+1);
    for (int i = 1; i <= n; i++){
        cin >> sup_num[i];
        if (sup_num[i] != -1){
            staff[sup_num[i]].push_back(i);
        }
    }
    
    while(m--){
        int i;
        long long w;
        cin >> i >> w;
        result[i] += w;
    }
    
    dfs(1);
    
    for(int i = 1; i <= n; i++){
        cout << result[i] << ' ';
    }
    
    return 0;
}