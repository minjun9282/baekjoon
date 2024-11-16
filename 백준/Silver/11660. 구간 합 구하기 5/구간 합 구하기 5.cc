#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> table(N, vector<int>(N, 0));
    int x;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> x;
            if (j > 0){
                table[i][j] = table[i][j-1] + x;
            }
            else{
                table[i][j] += x;
            }
        }
    }
    while(M--){
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        int result = 0;
        for (int i = x1 - 1; i <= x2 - 1; i++){
            result += (table[i][y2-1] - table[i][y1-2]);
        }
        cout << result << '\n';
    }

    return 0;
}
