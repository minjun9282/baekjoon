#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int S;
	cin >> S;
	long long int max = sqrt(2 * S);
	while (true) {
		if (((max * (max + 1) / 2) <= S) && (((max + 1) * (max + 2) / 2) > S))
			break;
		else {
			max--;
		}
	}
	cout << max << '\n';


	return 0;
}