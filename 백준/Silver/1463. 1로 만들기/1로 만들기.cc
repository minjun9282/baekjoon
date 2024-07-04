#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int arr[N + 1] = {0};

    for (int i = 2; i <= N; i++) {
        arr[i] = arr[i - 1] + 1;

        if (i % 2 == 0) {
            arr[i] = min(arr[i], arr[i / 2] + 1);
        }
        if (i % 3 == 0) {
            arr[i] = min(arr[i], arr[i / 3] + 1);
        }
    }
    cout << arr[N] << '\n';
    
    return 0;
}