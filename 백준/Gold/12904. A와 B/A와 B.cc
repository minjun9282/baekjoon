#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool changestot(string S, string T);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string S, T;
	cin >> S >> T;
	if (changestot(S, T) == true) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}

	return 0;
}

bool changestot(string S, string T) {
	while (T.length() != S.size()) {
		if (T[T.size() - 1] == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
	if (T == S) {
		return true;
	}
	else {
		return false;
	}
}