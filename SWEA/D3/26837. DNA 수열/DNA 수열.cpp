#include<iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	//S의 i번째 문자부터 j번째 문자까지를 순서대로 만든 문자열을 T라고 할 때,
    //T의 문자들을 섞어서 T와 반전 관계에 있는 문자열을 만들 수 있다.
    //'A'-'T' // 'G'-'C'
    //1<=i<=j<=n일때 j = i-1+2k (k>=1)여야 함. 모든 조합을 검사하되 A-T, G-C의 갯수가 pair가 맞아야함.
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        cin >> n;
        string s;
        cin >> s;
        int result = 0;
        for (int i = 0; i <n-1; i++){
            int num_A = 0;
            int num_T = 0;
            int num_C = 0;
            int num_G = 0;
            if (s[i] == 'A') num_A++;
            else if (s[i] == 'T') num_T++;
            else if (s[i] == 'C') num_C++;
            else if (s[i] == 'G') num_G++;
            
        	for (int j = i+1; j < n; j++){
                if (s[j] == 'A'){
                    num_A++;
                }
                else if (s[j] == 'T'){
                    num_T++;
                }
                else if (s[j] == 'C'){
                    num_C++;
                }
                else{
                    num_G++;
                }
				if ((j-i+1) % 2 == 0){
                    if (num_A == num_T && num_C == num_G){
                        result++;
                    }
                }
            }
        }
		cout << result << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}