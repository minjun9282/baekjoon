#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    queue<int> que;
    int i = 1;
    while(i < N + 1){
        que.push(i);
        i++;
    }
    cout << '<';
    while(!que.empty()){
        for (int i = 0; i < K - 1; i++){
            que.push(que.front());
            que.pop();
        }
        cout << que.front();
        que.pop();
        if (!que.empty()){
            cout << ", ";
        }
    }
    cout << '>';
    
    return 0;
}