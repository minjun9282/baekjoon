#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int case_num;
        cin >> case_num;
        vector<int> arr(8);
        for (int i = 0; i < 8; ++i){
        	cin >> arr[i];
        }
        int cnt = 0;
        int curr_idx;
        bool found = false;
        while(!found){
            for (int j = 1; j <= 5; j++){
                curr_idx = cnt % 8;
            	if (arr[curr_idx] - j <= 0){
                	arr[curr_idx] = 0;
                    cnt++;
                    found = true;
                    break;
                }
                else{
                	arr[curr_idx] = arr[curr_idx]-j;
                    cnt++;
                }
            }
        }
        int start_idx = cnt % 8;
        vector<int> answer;
        for (int i = start_idx; i < 8; i++){
        	answer.push_back(arr[i]);
        }
        for (int i = 0; i < start_idx; i++){
            answer.push_back(arr[i]);
        }
        cout << '#' << test_case << " ";
        for (int i = 0; i < 8; i++){
        	cout << answer[i];
            if (i != 7){
        	cout << " ";
            }
            else{
                cout << '\n';
            }
        }  
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}