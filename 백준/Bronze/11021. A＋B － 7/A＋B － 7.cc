#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, A, B;
    cin >> T;
    for (int i = 1; i < T + 1; i++){
        cin >> A >> B;
        cout << "Case #" << i << ": " << A + B << '\n';
    }
    
    return 0;
}