#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int front_pt, rear_pt;
	int cases = 0;
	int temp = 0;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (front_pt = 0; front_pt < N; front_pt++) {
		rear_pt = front_pt;
		while (rear_pt != N) {
			temp += arr[rear_pt];
			rear_pt++;
			if (temp == M) {
				cases++;
			}
		}
		temp = 0;
	}
	cout << cases << '\n';
	
	delete[] arr;

	return 0;
}