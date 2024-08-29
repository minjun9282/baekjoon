#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> attribute(N);
    
    for (int i = 0; i < N; i++) {
        cin >> attribute[i];
    }
    
    sort(attribute.begin(), attribute.end());
    int num_teams = 0;
    int front = 0, back = N - 1;
    
    while (front < back) {
        if (attribute[back] + attribute[front] >= M) {
            num_teams++;
            back--;
            front++;
        } else {
            front++;
        }
    }
    
    cout << num_teams << '\n';
    
    return 0;
}
