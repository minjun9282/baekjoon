#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    
    vector<long long> ans(N+1);
    ans[1] = 0;
    
    if (N > 1){
        ans[2] = 1;
        for (int i = 3; i <= N; i++){
            ans[i] = (i-1) * (ans[i-1] + ans[i-2]) % 1000000000;
        }
    }
    cout << ans[N] << '\n';
    
    return 0;
}