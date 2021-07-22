#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	char* arr = new char[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = N - 5; i < N; i++) {
		cout << arr[i];
	}
	
	delete[] arr;

	return 0;
}