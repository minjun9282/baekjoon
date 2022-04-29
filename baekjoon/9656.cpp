#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    //창영이는 4k나 4k-2를 만들 수 있는 입장
    //상근이는 4k-1이나 4k-3을 만들 수 있는 입장
    if(N % 4 == 0 || N % 4 == 2){
        cout << "SK" << '\n';
    }
    else{
        cout << "CY" << '\n';
    }

    return 0;
}
