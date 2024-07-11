#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int result = 0;
    vector<vector<int>> v(N, vector<int>(3));
    v[0][0] = 1; // 있는 경우
    v[0][1] = 1; //오른쪽에 있는 경우
    v[0][2] = 1; //양쪽에 없는 경우
    for (int i = 1; i < N; i++){
        v[i][0] = (v[i-1][1] + v[i-1][2]) % 9901;
        v[i][1] = (v[i-1][0] + v[i-1][2]) % 9901;
        v[i][2] = (v[i-1][0] + v[i-1][1] + v[i-1][2]) % 9901;
    }
    cout << (v[N-1][0] + v[N-1][1] + v[N-1][2]) % 9901 << '\n';
    
    return 0;
}