#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    vector<int> column;
    for(int i = 0; i < num_list.size() / n; i++){
        answer.push_back(column);
        for(int j = 0; j < n; j++){
            answer[i].push_back(num_list[n * i + j]);
        }
    }
    
    return answer;
}