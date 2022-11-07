#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.setf(ios::right);
    int N;
    string asterik = "*";
    cin >> N;
    for (int i = 0; i < N; i++){
        cout << setw(N) << asterik << '\n';
        asterik += "*";
    }
    
    return 0;
}
