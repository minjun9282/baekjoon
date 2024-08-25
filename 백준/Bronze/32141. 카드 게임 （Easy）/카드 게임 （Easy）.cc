#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, H;
    cin >> N >> H;
    vector<int> vec(N);
    
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    
    int sum = 0;
    
    for (int i = 0; i < N; i++) {
        sum += vec[i];
        if (sum >= H) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    
    cout << -1 << '\n';

    return 0;
}
