#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int N, R;
    long long int result;
    cin >> N >> R;
    result = 2 * R + N - 1;
    cout << result << '\n';

    return 0;
}