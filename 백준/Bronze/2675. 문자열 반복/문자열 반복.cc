#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num_case;
	int R;
	string S;
	string result;
	cin >> num_case;

	int i = 0;
	while (i < num_case) {
		int j = 0;
		cin >> R >> S;
		for (int i = 0; i < S.length(); i++) {
			while (j < R) {
				result += S[i];
				j++;
			}
			j = 0;
		}
		cout << result << '\n';
		result.clear();
		i++;
	}

	return 0;
}