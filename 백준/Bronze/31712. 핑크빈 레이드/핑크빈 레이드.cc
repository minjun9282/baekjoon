#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C_u, D_u, C_d, D_d, C_p, D_p, H;
    cin >> C_u >> D_u;
    cin >> C_d >> D_d;
    cin >> C_p >> D_p;
    cin >> H;

    int time = 0;
    int total_damage = 0;

    while (true) {
        if (time % C_u == 0) {
            total_damage += D_u;
        }
        if (time % C_d == 0) {
            total_damage += D_d;
        }
        if (time % C_p == 0) {
            total_damage += D_p;
        }
        if (total_damage >= H) {
            break;
        }
        time++;
    }

    cout << time << '\n';

    return 0;
}
