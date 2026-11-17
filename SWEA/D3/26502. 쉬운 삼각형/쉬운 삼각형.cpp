#include<iostream>
#include <cmath>
#include <vector>
#include <set>
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
		int N;
        cin >> N;
        //삼각형의 한 변은 x축, 또 한변은 y축에 평행해야함. -> 직각인 꼭짓점을 (a,b)라 하면 나머지 두 점은 각각 (x, b), (a, y)형식
        //100C3은 100*99*98/6 이므로 약 16만가지 -> 다 해봐도 됨.
        vector<pair<int, int>> coords;
     	int x, y;
        for (int i = 0; i < N; ++i){
            cin >> x >> y;
            coords.push_back({x, y});
        }
        int result = 0;
        for (int i = 0; i < N-2; i++){
        	for (int j = i+1; j < N-1; j++){
            	for (int k = j+1; k < N; k++){
                    int width, height;
                    //직각 삼각형인지부터 검증해야함.
                	set<int> x_coords;
                    set<int> y_coords;
                    x_coords.insert(coords[i].first);
                    x_coords.insert(coords[j].first);
                    x_coords.insert(coords[k].first);
                    y_coords.insert(coords[i].second);
                    y_coords.insert(coords[j].second);
                    y_coords.insert(coords[k].second);
                    if (x_coords.size() == 2 && y_coords.size() == 2){
                    	width = *x_coords.rbegin() - *x_coords.begin();
                        height = *y_coords.rbegin() - *y_coords.begin();
                        int area = width * height;
                    	if (area > result){
                    		result = area;
                    	}
                    }         
                }       
            }      
        }
        cout << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}