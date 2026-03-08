#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int T;
string min_num, max_num;
/*
2개:1
3개:7
4개:4
5개:5 3 2
6개:9 6 0
7개:8
*/

string dp[101]; //dp[n] 성냥 n개를 사용해서 만들 수 있는 가장 작은 숫자

void cal_max_min(int n, string& min_num, string& max_num) {

	// 성냥개비를 모두 사용해야 함
	// 1. 자릿수가 커지거나 작아지는게 1순위
	// 2. 자릿수가 동일한 경우 큰 숫자가 앞에올수록 큰 수, 작은 숫자가 앞에 올수록 작은 수
	// 3. 0은 맨 앞에 올 수 없음

	// 다 해볼필요 없이 floor(n / 2)가 최대자릿수, ceil(n/7)이 최소 자릿수
	// n이 2~100이니까 1 <= min_digits <= 15, 1 <= max_digits <= 50

	int min_digits = (n + 6) / 7;
	int max_digits = n / 2;

	//1. 가장 작은 수
	//최소 숫자에 자릿수 한개에 해당하는 숫자 붙이면서 최소값을 만듦

	for (int i = 0; i <= 100; i++) dp[i] = "";

	dp[2] = "1";
	dp[3] = "7";
	dp[4] = "4";
	dp[5] = "2";
	dp[6] = "6"; //0은 못오니까 이때는 6
	dp[7] = "8";

	vector<int> matches = { 2,3,4,5,6,7 }; //사용하는 성냥 갯수
	vector<string> digits = { "1","7","4","2","0","8" }; //사용하는 성냥 갯수에 매칭되는 자연수

	for (int i = 8; i <= n; i++) {
		for (int j = 0; j < 6; j++) {
			int m = matches[j];
			if (i - m < 2) {
				continue;
			}

			string candidate = dp[i - m] + digits[j];
			//값이 없거나 자릿수가 더 작으면 갱신
			//자릿값이 같으면 숫자가 더 작으면 갱신
			if (dp[i] == "" || candidate.length() < dp[i].length() || (candidate.length() == dp[i].length() && candidate < dp[i])) {
				dp[i] = candidate;
			}
		}
	}

	min_num = dp[n];

	//2. 가장 큰 수
	//자릿수를 최대화하면 숫자가 최대가 됨 - 숫자 1을 최대한 많이 써야함

	max_num = "";

	if (n % 2 == 1) {
		max_num += '7';
		for (int i = 0; i < (n - 3) / 2; i++) {
			max_num += '1';
		}
	}
	else {
		for (int i = 0; i < n / 2; i++) {
			max_num += '1';
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cal_max_min(n, min_num, max_num);
		cout << min_num << " " << max_num << '\n';
	}

	return 0;
}