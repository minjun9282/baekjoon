#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int sum, diff;
        cin >> sum >> diff;
        cout << (sum+diff) / 2 << " " << (sum-diff) / 2 << '\n';


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}