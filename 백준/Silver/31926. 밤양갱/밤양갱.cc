#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    // N=2: daldi - 5초 dal 1초 go 2초 daldidalgo 1초 daldida 1초 n 1초 -> 11초
    // daldidalgo -> 8초, daldidan -> 2초
    // daldidalgo를 몇번 만에 N번 작성할 수 있는가?
    int i = 1;
    int num = 0;
    while (i < N + 1){
        num += 1;
        i = i * 2;
        
    }
    cout << 8 + num + 1 << '\n';
    
    return 0;
}

