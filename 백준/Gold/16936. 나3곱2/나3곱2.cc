#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

bool compare(tuple<long long int, long long int, long long int> a, tuple<long long int, long long int, long long int> b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	long long int num;
	vector<tuple<int, int, long long int>> submultiple;
	vector<long long int> progression;
	for (int i = 0; i < N; i++) {
		cin >> num;
		progression.push_back(num);
		int j = 0;
		while (num % 3 == 0) {
			num = num / 3;
			j++;
		}
		int k = 0;
		num = progression.back();
		while (num % 2 == 0) {
			if (num % 2 == 0) {
				num = num / 2;
			}
			k++;
		}
		num = num * (long long int)pow(2, k);
		submultiple.push_back(make_tuple(j, k, num));
	}
	sort(submultiple.begin(), submultiple.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << get<2> (submultiple[i]) << " ";
	}

	return 0;
}

bool compare(tuple<long long int, long long int, long long int> a, tuple<long long int, long long int, long long int> b){
	if (get<0> (a) == get<0> (b)) {
		return get<1> (a) < get<1> (b);
	}
	else {
		return get<0> (a) > get<0> (b);
	}
}