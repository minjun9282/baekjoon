#include <iostream>
#include <queue>
#include <stack>
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
    vector<int> path(100001);
    path[N] = N;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if (now - 1 >= 0){
            if (check[now - 1] == false){
                check[now - 1] = true;
                dist[now - 1] = dist[now] + 1;
                q.push(now - 1);
                path[now - 1] = now;
            }
        }
        if (now + 1 <= 100000){
            if (check[now + 1] == false){
                check[now + 1] = true;
                dist[now + 1] = dist[now] + 1;
                q.push(now + 1);
                path[now + 1] = now;
            }
        }
        if (now * 2 <= 100000){
            if (check[now * 2] == false){
                check[now * 2] = true;
                dist[now * 2] = dist[now] + 1;
                q.push(now * 2);
                path[now * 2] = now;
            }
        }
    }
    cout << dist[K] << '\n';
    stack<int> stack;
    if (N != K){
        stack.push(K);
    }
    while(true){
        if (path[K] == N){
            stack.push(path[N]);
            break;
        }
        else{
            stack.push(path[K]);
            K = path[K];
        }
    }
    while(!stack.empty()){
        cout << stack.top() << " ";
        stack.pop();
    }
    
    return 0;
}