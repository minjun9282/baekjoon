#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int temp, i = 1;
	cin >> temp;
	int min = temp;
	int max = temp;
	while (i < N) {
		cin >> temp;
		if (temp > max) {
			max = temp;
		}
		if (temp < min) {
			min = temp;
		}
		i++;
	}

	cout << min * max << '\n';
	
	return 0;
}