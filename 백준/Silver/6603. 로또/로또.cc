#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[20];
bool c[20];
vector<int> v;

void go(int index, int start, int n){
    if (index == 6){
        for (int i = 0; i < 6; i++){
            cout << v[a[i]];
            if (i != 5){
                cout << " ";
            }
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++){
        if (c[i]){
            continue;
        }
        c[i] = true;
        a[index] = i;
        go(index + 1, i + 1, n);
        c[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true){
        int num;
        cin >> num;
        if (num == 0){
            break;
        }
        v.clear(); 
        v.resize(num);
        fill(c, c + num, false); 

        for (int i = 0; i < num; i++){
            cin >> v[i];
        }
        go(0, 0, num);
        cout << '\n'; 
    }

    return 0;
}