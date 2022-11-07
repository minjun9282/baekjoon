#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num, i = 0;
    int remainder[10];

    while (i < 10) {
        cin >> num;
        remainder[i] = (num % 42);
        i++;
    }
    for (int j = 0; j < 9; j++) {
        for (int k = j + 1; k < 10; k++) {
            if (remainder[j] != -1) {
                if (remainder[j] == remainder[k]) {
                    remainder[k] = -1;
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 10; i++) {
        if (remainder[i] != -1) {
            result++;
        }
    }
    cout << result << '\n';

    return 0;
}