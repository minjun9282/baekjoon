#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, min_result = 0;
	int quo, rem;
	cin >> N;
	quo = N / 15;
	rem = N % 15;
	if((rem % 15 == 1) || (rem % 15 == 2)){
		cout << -1 << '\n';
	}
	else if((rem % 15 == 4) || (rem % 15 == 7)){
		cout << -1 << '\n';
	}
	else{
		min_result += (quo * 3);
		if(rem < 6){
			min_result += 1;
		}
		else if((rem == 12) || (rem == 14)){
			min_result += 4;
		}
		else if(rem % 2 == 0){
			min_result += 2;
		}
		else{
			min_result += 3;
		}
		cout << min_result << '\n';
	}

	return 0;
}