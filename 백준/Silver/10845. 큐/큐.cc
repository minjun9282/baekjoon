#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> que;

    while (N--){
        string command;
        cin >> command;

        if (command == "push"){
            int num;
            cin >> num;
            que.push(num);
        }
        else if (command == "pop"){
            if (!que.empty()){
                cout << que.front() << '\n';
                que.pop();
            }
            else{
                cout << -1 << '\n';
            }
        }
        else if (command == "size"){
            cout << que.size() << '\n';
        }
        else if (command == "empty"){
            cout << que.empty() << '\n'; 
        }
        else if (command == "front"){
            if (!que.empty()){
                cout << que.front() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
        else if (command == "back"){
            if (!que.empty()){
                cout << que.back() << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}
