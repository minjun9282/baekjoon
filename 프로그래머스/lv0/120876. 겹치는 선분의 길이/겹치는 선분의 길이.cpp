#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int min_num = min(min(lines[0][0], lines[1][0]), lines[2][0]);
    int max_num = max(max(lines[0][1], lines[1][1]), lines[2][1]);
    vector<vector<int>> numbers;
    vector<int> s;
    for(int i = 0; i < max_num - min_num + 1; i++){
        numbers.push_back(s);
        numbers[i].push_back(min_num + i);
        numbers[i].push_back(0);
    }
    int k = 0;
    for(int j = 0; j < lines.size(); j++){
        while(true){
            if(numbers[k][0] == lines[j][1]){
                break;
            }
            if(numbers[k][0] > lines[j][0] - 1){
                numbers[k][1]++;
            }
            k++;
        }
        k = 0;
    }
    int m = 0;
    while(m < numbers.size()){
        if(numbers[m][1] > 1){
            answer++;
        }
        m++;
    }
    return answer;
}

