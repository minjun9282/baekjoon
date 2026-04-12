#include <iostream>
#include <vector>
using namespace std;

void rotate(int x_i, int d_i, int k_i, int N, int M, vector<vector<int>>& plate) {
	//x_i: 번호가 x_i의 배수인 원판 모두 해당
	//d_i: 0 이면 시계, 1이면 반시계
	//k_i: k번 회전
	for (int i = x_i;  i < N+1; i += x_i) {
		int temp_k = k_i;
		while (temp_k--) {
			if (d_i == 0) {// 시계방향 회전:맨 뒤 원소를 제일 앞에 넣어주면 됨.
				int last_num = plate[i][M];
				for (int j = M; j > 1; j--) {
					plate[i][j] = plate[i][j-1];
				}
				plate[i][1] = last_num;
			}
			else {// 반시계 방향 회전: 맨 앞 원소를 제일 뒤에 넣어주면 됨.
				int first_num = plate[i][1];
				for (int j = 1; j < M; j++) {
					plate[i][j] = plate[i][j + 1];
				}
				plate[i][M] = first_num;
			}
		}
	}
}


void manipulate(int N, int M, vector<vector<int>> &plate) {
	//1. 인접하면서 같은 수가 있으면 모두 찾고 삭제 -> 0으로 처리
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
    bool found = false;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M+1; j++) {
            if (plate[i][j] == 0) {
                continue;
            }
            int next_j;
            if (j == M) {
                next_j = 1;
            }
            else {
                next_j = j + 1;
            }
            if (plate[i][j] == plate[i][next_j]) {
                visited[i][j] = true;
                visited[i][next_j] = true;
                found = true;
            }
            if (i < N && plate[i][j] == plate[i + 1][j]) {
                visited[i][j] = true;
                visited[i + 1][j] = true;
                found = true;
            }
        }
    }
    if (found) {
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < M + 1; j++) {
                if (visited[i][j] == true) {
                    plate[i][j] = 0;
                }
            }
        }
    }
    else {//2. 없을 경우에는 원판에 적힌 수의 평균 구하고 평균보다 큰 수에서는 1빼고 작은 수에는 1 더함
        float sum = 0;
        int num_count = 0;
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < M + 1; j++) {
                if (plate[i][j] != 0) {
                    sum += plate[i][j];
                    num_count++;
                }
            }
        }
        float avg = sum / num_count;
        for (int i = 1; i < N+1; i++) {
            for (int j = 1; j < M+1; j++) {
                if (plate[i][j] != 0 && plate[i][j] < avg) {
                    plate[i][j] += 1;
                }
                else if (plate[i][j] != 0 && plate[i][j] > avg) {
                    plate[i][j] -= 1;
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M, T;
	cin >> N >> M >> T;

	vector<vector<int>> plate(N+1, vector<int>(M+1, 0));
	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < M+1; j++) {
			cin >> plate[i][j];
		}
	}
	while (T--) {
		int x_i, d_i, k_i;
		cin >> x_i >> d_i >> k_i;
		rotate(x_i, d_i, k_i, N, M, plate);
        manipulate(N, M, plate);
	}
    int result = 0;
    for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < M+1; j++) {
            result += plate[i][j];
        }
    }
    cout << result << '\n';

	return 0;
}