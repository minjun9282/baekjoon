#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

//택시 기하학에서 반지름이 R인 원은 대각선의 길이가 2R인 정사각형을 생각하면 된다.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(6);

	double pi = M_PI;
	int R;
	cin >> R;
	
	cout << R * R * pi << '\n';
	cout << 2 * R * R << '\n';

	return 0;
}