#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, N, A, B;
    cin >> T;
    int i = 1;
    while(i <= T){
        cin >> N;
        cin >> A >> B;
        cout << "Material Management " << i << '\n';
        int u_i, v_i;
        while(N--){
            cin >> u_i >> v_i;
        }
        cout << "Classification ---- End!" << '\n';
        i++;
    }
    
    
    return 0;
}