#include <iostream>
#include <vector>
using namespace std;

void change_switches(vector<int>& status_swithces, int gender, int number) {
	if (gender == 1) {// 남자는 입력된 수의 배수에 해당하는 스위치의 상태를 바꿈
		for (int i = 1; i * number < status_swithces.size(); i++) {
			if (status_swithces[i * number] == 1) {
				status_swithces[i * number] = 0;
			}
			else {
				status_swithces[i * number] = 1;
			}
		}
	}
	else { //여자는 자기 번호를 중심으로 좌우가 대칭이면서 가장 많은 스위치를 포함하는 구간을 찾아서 다 바꿈
		//일단 자기 자신은 무조건 바꿈
		int curr = number;
		if (status_swithces[number] == 1) {
			status_swithces[number] = 0;
		}
		else {
			status_swithces[number] = 1;
		}
		int next = number + 1;
		int prev = number - 1;
		while (next < status_swithces.size() && prev > 0) {
			if (status_swithces[next] != status_swithces[prev]) {
				break;
			}
			else {
				if (status_swithces[next] == 0) {
					status_swithces[next] = 1;
					status_swithces[prev] = 1;
				}
				else {
					status_swithces[next] = 0;
					status_swithces[prev] = 0;
				}
			}
			next++;
			prev--;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int num_switches, num_students;
	cin >> num_switches;
	vector<int> status_switches(num_switches+1);
	for (int i = 1; i < num_switches+1; i++) {
		cin >> status_switches[i];
	}
	cin >> num_students;

	for (int j = 0; j < num_students; j++) {
		int gender, num;
		cin >> gender >> num;
		change_switches(status_switches, gender, num);
	}
	//출력 20개씩 끊어서 함
	int quo = num_switches / 20;
	int rem = num_switches % 20;
	int i = 0;
	while (quo > 0) {
		for (int j = 20 * i + 1; j < 20 * (i+1) + 1; j++) {
			cout << status_switches[j] << " ";
		}
		cout << '\n';
		i++;
		quo--;
	}
	for (int k = i * 20 + 1; k < i * 20 + rem + 1; k++) {
		cout << status_switches[k] << " ";
	}
	cout << '\n';

	return 0;
}