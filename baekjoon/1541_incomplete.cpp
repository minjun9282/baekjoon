#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string cal_form;
	cin >> cal_form;
	int result = 0;

	// -�� �Ŀ� ���Եȴٸ� -�� ù��° ��ġ ã��
	bool minus = false;
	int first_minus;
	if (cal_form.find('-') != string::npos) {
		minus = true;
		first_minus = cal_form.find('-');
	}

	// -�� - ���̿� �ִ� +�� -�� �ٲٱ�
	// �� ���� ���� ���� �� �ڿ��� -�� �ִٰ� ����
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

	cout << cal_form << '\n';

	return 0;
}