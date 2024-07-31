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
        cin >> v[i];
    }
    if (prev_permutation(v.begin(), v.end())){
        for (int i = 0; i < N; i++){
            cout << v[i] << " ";
        }
    }
    else{
        cout << "-1" << '\n';
    }
    cout << '\n';
    
    return 0;
}