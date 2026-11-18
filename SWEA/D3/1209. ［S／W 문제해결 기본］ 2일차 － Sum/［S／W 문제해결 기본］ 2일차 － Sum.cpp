#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int test_case;
	int T;
	T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int case_number;
        cin >> case_number;
        vector<vector<int>> arr(100, vector<int>(100));
        for (int row = 0; row < 100; ++row){
        	for (int col = 0; col < 100; ++col){
            	cin >> arr[row][col];
            }
        }
        int max_sum = 0;
        //1.행의 합 비교
        for (int row = 0; row < 100; ++row){
        	int curr_sum = 0;
            for (int col = 0; col < 100; ++col){
            	curr_sum += arr[row][col];
            }
            if (curr_sum > max_sum){
            	max_sum = curr_sum;
            }
        }
        //2.열의 합 비교
        for (int col = 0; col < 100; ++col){
        	int curr_sum = 0;
            for (int row = 0; row < 100; ++row){
            	curr_sum += arr[row][col];
            }
            if (curr_sum > max_sum){
            	max_sum = curr_sum;
            }
        }
        //대각 합 비교
        int curr_sum = 0;
        for (int i = 0; i < 100; ++i){
            curr_sum += arr[i][i];
        }
        if (curr_sum > max_sum){
        	max_sum = curr_sum;
        }
        curr_sum = 0;
        for (int i = 99; i >= 0; --i){
        	curr_sum += arr[i][99-i];
        }
        if (curr_sum > max_sum){
        	max_sum = curr_sum;
        }
        cout << '#' << test_case << " " << max_sum << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}