#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	char* arr = new char[N];
	int bitecode = N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	
	for (int j = 0; j < N; j++) {
		if(arr[j] == 'J'){
			bitecode--;
			arr[j] = '\0';
		}
		else if (arr[j] == 'A') {
			bitecode--;
			arr[j] = '\0';
		}
		else if (arr[j] == 'V') {
			bitecode--;
			arr[j] = '\0';
		}
	}
	if (bitecode == 0) {
		cout << "nojava" << '\n';
	}
	else {
		for (int k = 0; k < N; k++) {
			if(arr[k] != '\0')
				cout << arr[k];
		}
	}

	delete[] arr;
	

	return 0;
}