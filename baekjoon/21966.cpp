#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	string s;
	cin >> s;
	if (N < 26) {
		cout << s << '\n';
	}
	else {
		if (s.substr(11, N - 22).find('.') == string::npos) { //없으면 string::npos반환
			cout << s.substr(0, 11);
			cout << "...";
			cout << s.substr(N - 11, 11);
		}
		else {
			if (s.substr(11, N - 22).find('.') == N - 23) {
				cout << s.substr(0, 11);
				cout << "...";
				cout << s.substr(N - 11, 11);
			}
			else {
				cout << s.substr(0, 9);
				cout << "......";
				cout << s.substr(N - 10, 10);
			}
		}
	}

	return 0;
}