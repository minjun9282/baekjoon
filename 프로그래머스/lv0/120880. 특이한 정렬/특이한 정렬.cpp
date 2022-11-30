#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<vector<int>> distance;
    vector<int> s;
    int temp;
    for(int i = 0; i < numlist.size(); i++){
        distance.push_back(s);
        distance[i].push_back(abs(numlist[i] - n));
        distance[i].push_back(i);
    }
    sort(distance.begin(), distance.end());
    for(int j = 0; j < distance.size() - 1; j++){
        if(distance[j][0] == distance[j + 1][0]){
            if(numlist[distance[j][1]] < numlist[distance[j+1][1]]){
                temp = distance[j][1];
                distance[j][1] = distance[j+1][1];
                distance[j+1][1] = temp;
            }
        }
    }
    for(int k = 0; k < distance.size(); k++){
        answer.push_back(numlist[distance[k][1]]);
    }
    return answer;
}

