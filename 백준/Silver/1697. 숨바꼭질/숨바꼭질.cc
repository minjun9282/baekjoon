#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    bool check[100001];
    int dist[100001] = {0};
    queue<int> q;
    check[N] = true;
    q.push(N);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if (now - 1 >= 0){
            if (check[now - 1] == false){
                q.push(now - 1);
                check[now - 1] = true;
                dist[now - 1] = dist[now] + 1;
            }
        }
        if (now + 1 < 100001){
            if (check[now + 1] == false){
                q.push(now + 1);
                check[now + 1] = true;
                dist[now + 1] = dist[now] + 1;
            }
        }
        if (now * 2 < 100001){
            if (check[now * 2] == false){
                q.push(now * 2);
                check[now * 2] = true;
                dist[now * 2] = dist[now] + 1;
            }
        }
    }
    cout << dist[K] << '\n';
    
    return 0;
}