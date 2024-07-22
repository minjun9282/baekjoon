#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    bool check[100001];
    int time[100001] = {0};
    check[N] = true;
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if (now * 2 <= 100000){
            if (check[now * 2] == false){
                check[now * 2] = true;
                time[now * 2] = time[now];
                q.push(now * 2);
            }
        }
        if (now - 1 >= 0){
            if (check[now - 1] == false){
                check[now - 1] = true;
                time[now - 1] = time[now] + 1;
                q.push(now - 1);
            }
        }
        if (now + 1 <= 100000){
            if (check[now + 1] == false){
                check[now + 1] = true;
                time[now + 1] = time[now] + 1;
                q.push(now + 1);
            }
        }
    }
    cout << time[K] << '\n';
    
    return 0;
}