#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = 0;
    while(true){
        if(i % 3 != 0 && to_string(i).find('3') == string::npos){
            n--;
        }
        if(n == 0){
            answer = i;
            break;
        }
        else{
            i++;
        }
    }
    
    
    return answer;
}