#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	int* card = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	int result = 0;
	int gap = M;
	int temp;

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				temp = card[i] + card[j] + card[k];
				if ((M - temp <= gap)&&(temp <= M)) {
					gap = abs(M - temp);
					result = temp;
				}
			}
		}
	}
	cout << result << '\n';
    
	return 0;
}