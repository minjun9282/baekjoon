#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
    sort(v.begin(), v.end());
    int max = 0;
    do{
        int temp = 0;
        for (int i = 0; i < N - 1; i++){
            temp += abs(v[i] - v[i + 1]);
        }
        if (temp > max){
            max = temp;
        }
        
    } while (next_permutation(v.begin(), v.end()));
    cout << max << '\n';
    
    return 0;
}