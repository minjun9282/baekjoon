#include <iostream>
using namespace std;

int num_of_results(int max);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int max;
	cin >> max;
	cout << num_of_results(max) << '\n';

	return 0;
}

int num_of_results(int max) {
	int result = 0;
	if ((0 < max) && (max < 100)) {
		return max;
	}
	else {
		result += 99;
	}
	int i = 100;
	while (i < max + 1) {
		if (((i / 100) - ((i % 100) / 10)) == (((i % 100) / 10) - (i % 10)))
			result += 1;
		i++;
	}
	return result;

}