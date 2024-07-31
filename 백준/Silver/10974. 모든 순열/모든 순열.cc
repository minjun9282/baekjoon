#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++){
        v[i] = i + 1;
    }
    for (int i = 0; i < N; i++){
        cout << v[i];
        if (i != N - 1){
            cout << " ";
        }
    }
    cout << '\n';
    while(next_permutation(v.begin(), v.end())){
        for (int i = 0; i < N; i++){
            cout << v[i];
            if (i != N - 1){
                cout << " ";
            }
        }
        cout << '\n';
    }
    
    return 0;
}