#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> numbers;
	vector<int> num_counts(8001, 0);
	int total_sum = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		total_sum += x; // 산술 평균 
		num_counts[x + 4000]++;
		numbers.push_back(x);
	}
	sort(numbers.begin(), numbers.end());
	//1.산술 평균
	cout << round(float(total_sum) / N)+ 0.0f << '\n';

	//2.중앙값
	int mid_index = N / 2;
	cout << numbers[mid_index] << '\n';

	//3.최빈값
	auto max_idx = max_element(num_counts.begin(), num_counts.end());
	int max_counts = *max_idx;
	vector<int> indices;
	auto it = find(num_counts.begin(), num_counts.end(), max_counts);
	while(it != num_counts.end()) {
		indices.push_back(distance(num_counts.begin(), it));
		it = find(next(it), num_counts.end(), max_counts);
	}
	if (indices.size() >= 2) {
		cout << indices[1]-4000 << '\n';
	}
	else {
		cout << indices[0]-4000 << '\n';
	}

	//4.범위
	auto max_it = max_element(numbers.begin(), numbers.end());
	auto min_it = min_element(numbers.begin(), numbers.end());
	int max_num = *max_it;
	int min_num = *min_it;
	cout << max_num - min_num << '\n';

	return 0;
}