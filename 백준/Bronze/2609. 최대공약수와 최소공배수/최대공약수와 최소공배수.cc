#include <iostream>
#include <numeric>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int M, N;
    cin >> M >> N;
    cout << gcd(M, N) << '\n';
    cout << lcm(M, N) << '\n';
    
    return 0;
}