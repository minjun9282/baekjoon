#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
    int answer = 0;
    char arr_before[26] = {};
    char arr_after[26] = {};
    for(int i = 0; i < before.size(); i++){
        arr_before[(int)before[i] - 97]++;
        arr_after[(int)after[i] - 97]++;
    }
    bool possible = true;
    for(int i = 0; i < 26; i++){
        if(arr_before[i] != arr_after[i]){
            possible = false;
        }
    }
    if(possible == true){
        answer = 1;
    }
    else{
        answer = 0;
    }
    return answer;
}