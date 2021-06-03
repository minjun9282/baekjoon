#include <iostream>
#include <cmath>
using namespace std;

// �� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ����� ����ϱ�

int cal_GCD(int n, int m);
int cal_LCM(int n, int m);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int LCM;
	cout << cal_GCD(n, m) << '\n';
	cout << cal_LCM(n, m) << '\n';

	return 0;
}

int cal_GCD(int n, int m){
	int a, b, quo, rem;
	int result;
	if(n >= m){
		a = n;
		b = m;
	}
	else {
		a = m;
		b = n;
	}
	rem = a % b;
	if (rem == 0) {
		result = b;
		return result;
	}
	else {
		return cal_GCD(b, rem);
	}

}

int cal_LCM(int n, int m) {
	int LCM;
	int GCD = cal_GCD(n, m);	
	LCM = GCD * (n / GCD) * (m / GCD);
	return LCM;
}

/*
�ݺ����� Ȱ���� ��Ŭ���� ȣ����
// n > m �̶�� ����
int GCD(int n, int m) {
	int rem = n % m;
	while (rem != 0) {
		n = m;
		m = rem;
		rem = n % m;
	}
	return m;
}
*/


