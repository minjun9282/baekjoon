#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[7];
	int result = 0;
	int min = 100;
	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
		if (arr[i] % 2 != 0) {
			result += arr[i];
			if (arr[i] < min) {
				min = arr[i];
			}
		}
	}

	if (min == 100) {
		cout << -1 << '\n';
	}
	else {
		cout << result << '\n';
		cout << min << '\n';
	}


	return 0;
}