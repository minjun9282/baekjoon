#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string cal_form;
	cin >> cal_form;
	int result = 0;

	//1.-가 식에 포함된다면 -의 첫번째 위치 찾기
	bool minus = false;
	int first_minus;
	if (cal_form.find('-') != string::npos) {
		minus = true;
		first_minus = cal_form.find('-');
	}

	//2. -와 - 사이에 있는 +를 -로 바꾸기
		// 이 논리를 위해 식의 맨 뒤에는 -가 있다고 가정
	cal_form.push_back('-');
	cal_form.push_back('0');
	int next_minus;
	while (minus != false && first_minus < cal_form.length()) {
		next_minus = cal_form.find('-', first_minus + 1);
		for (int j = first_minus; j < next_minus; j++) {
			if (cal_form.at(j) == '+') {
				cal_form.replace(j, 1, "-");
			}
		}
		first_minus = next_minus;
	}

	//3. 변경한 식을 기반으로 결과값 계산
	string cal_form2 = "+" + cal_form;
	int sign;
	int next_sign;
	int num;
	int finished = 0;
	
	while (finished != cal_form2.length()) {
		sign = cal_form2.find('-', finished) < cal_form2.find('+', finished) ? cal_form2.find('-', finished) : cal_form2.find('+', finished);
		if (sign + 2 == cal_form2.length())
			break;
		next_sign = cal_form2.find('-', sign + 1) < cal_form2.find('+', sign + 1) ? cal_form2.find('-', sign + 1) : cal_form2.find('+', sign + 1);
		num = stoi(cal_form2.substr(sign + 1, next_sign - sign - 1));
		finished = sign + 1;
		if (cal_form2[sign] == '+') {
			result += num;
		}
		else {
			result -= num;
		}
	}
	
	cout << result << '\n';

	return 0;
}
