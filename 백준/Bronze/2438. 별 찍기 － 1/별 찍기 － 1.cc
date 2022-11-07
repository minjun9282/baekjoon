#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string asterik = "*";
    cin >> N;
    for (int i = 0; i < N; i++ ){
        cout << asterik << '\n';
        asterik += "*";
    }
    
    return 0;
}