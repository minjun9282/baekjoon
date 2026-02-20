#include <iostream>
#include <stack>
using namespace std;

stack<int> tower[4]; // 인덱스 1~3이 타워임

static inline int otherTower(int a, int b) {
    // {1,2,3} 타워 중 a,b가 아닌 나머지 하나
    return 6 - a - b;
}

static inline void move_disk(int from, int to) {
    int x = tower[from].top();
    tower[from].pop();
    tower[to].push(x);
    cout << from << ' ' << to << '\n';
}

/*
Move(n, src, dst):
  n-1개를 (src -> mid) 로 옮김
  n번째(맨 아래) 1개를 (src -> dst) 로 옮김
  n-1개를 (mid -> dst) 로 옮김

여기서 mid = otherTower(src, dst)
*/
void Move(int n, int src, int dst) {
    if (n == 0) return;
    int mid = otherTower(src, dst);
    
    Move(n - 1, src, mid);

    move_disk(src, dst);

    Move(n - 1, mid, dst);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = N; i >= 1; --i) {
        tower[1].push(i);
    }

    unsigned long long K = (1ULL << N) - 1ULL;
    cout << K << '\n';

    Move(N, 1, 3);

    return 0;
}
