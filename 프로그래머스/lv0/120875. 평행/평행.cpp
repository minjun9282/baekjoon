#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    bool find = false;
    if(((float)(dots[0][0] - dots[1][0]) / (float)(dots[0][1] - dots[1][1])) == ((float)(dots[2][0] - dots[3][0]) / (float)(dots[2][1] - dots[3][1]))){
        find = true;
    }
    if(((float)(dots[0][0] - dots[2][0]) / (float)(dots[0][1] - dots[2][1])) == ((float)(dots[1][0] - dots[3][0]) / (float)(dots[1][1] - dots[3][1]))){
        find = true;
    }
    if(((float)(dots[0][0] - dots[3][0]) / (float)(dots[0][1] - dots[3][1])) == ((float)(dots[1][0] - dots[2][0]) / (float)(dots[1][1] - dots[2][1]))){
        find = true;
    }
    if(find == true){
        answer = 1;
    }
    else{
        answer = 0;
    }
    return answer;
}