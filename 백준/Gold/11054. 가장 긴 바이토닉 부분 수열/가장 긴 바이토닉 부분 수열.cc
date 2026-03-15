#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> S(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	
	vector<int> dp_increase(N);
	vector<int> dp_decrease(N);
	//1. 가장 긴 증가하는 수열
	for (int i = 0; i < N; i++) {
		dp_increase[i] = 1; //일단 초기화
	}
	for (int i = 1; i < N; i++) {
		int index = 0;
		while (index < i) {
			if (S[i] > S[index]) {
				dp_increase[i] = max(dp_increase[i], dp_increase[index] + 1);
			}
			index++;
		}
	}

	//2. 가장 긴 감소하는 수열
	for (int i = 0; i < N; i++) {
		dp_decrease[i] = 1;
	}
	
	for (int i = N-2; i >= 0; i--) {
		int index = N-1;
		while (index > i) {
			if (S[i] > S[index]) {
				dp_decrease[i] = max(dp_decrease[i], dp_decrease[index] + 1);
			}
		index--;
		}
	}
	int max_result = 0;
	for (int i = 0; i < N; i++) {
		int sum = dp_increase[i] + dp_decrease[i] - 1;
		if (sum > max_result) {
			max_result = sum;
		}
	}
	
	cout << max_result << '\n';

	return 0;
}