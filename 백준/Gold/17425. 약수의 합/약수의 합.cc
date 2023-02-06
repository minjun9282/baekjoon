#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
	int max = 1000000;
	vector<long long int> d(max + 1, 1);
	for (int i = 2; i < max + 1; i++) {
		for (int j = 1; i * j < max + 1; j++) {
			d[i * j] += i;
		}
	}
	vector<long long int> s(max + 1, 1);
	for (int i = 2; i < max + 1; i++) {
		s[i] = s[i - 1] + d[i];
	}
	int T, num;
	cin >> T;
	int i = 0;
	while (i < T) {
		cin >> num;
		cout << s[num] << '\n';
		i++;
	}

	return 0;
}