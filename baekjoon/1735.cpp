#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num_a, num_b, deno_a, deno_b;
	int irr_num, irr_deno;
	cin >> num_a >> deno_a;
	cin >> num_b >> deno_b;
	irr_num = num_a * deno_b + num_b * deno_a;
	irr_deno = deno_a * deno_b;

	int gcd_irr = gcd(irr_num, irr_deno);

	irr_num = irr_num / gcd_irr;
	irr_deno = irr_deno / gcd_irr;

	cout << irr_num << " " << irr_deno << '\n';

	return 0;
}

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}