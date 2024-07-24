#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool has_digit(int num, const vector<int>& broken) {
    if (num == 0) {
        return find(broken.begin(), broken.end(), 0) != broken.end();
    }
    while (num > 0) {
        if (find(broken.begin(), broken.end(), num % 10) != broken.end()) {
            return true;
        }
        num /= 10;
    }
    return false;
}


int digit(int num) {
    if (num == 0) return 1;
    int dig = 0;
    while (num > 0) {
        num /= 10;
        dig++;
    }
    return dig;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> broken(M);
    for (int i = 0; i < M; i++) {
        cin >> broken[i];
    }

    int min_num = abs(N - 100);

    for (int i = 0; i <= 1000000; i++) {
        if (!has_digit(i, broken)) {
            int temp = abs(N - i) + digit(i);
            if (temp < min_num) {
                min_num = temp;
            }
        }
    }

    cout << min_num << '\n';

    return 0;
}