#include  <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int plugs;
	int result = 0;
	int i = 1;
	cin >> N;
	cin >> plugs;
	result += plugs;
	while (i < N) {
		cin >> plugs;
		result = result + plugs - 1;
		i++;
	}
	cout << result << '\n';

	return 0;
}