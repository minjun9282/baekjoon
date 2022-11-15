#include <string>
#include <numeric>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    b = b / gcd(a, b);
    int div_num = 1;
    while(true){
        if(b % 2 == 0){
            b = b / 2;
        }
        else if(b % 5 == 0){
            b = b / 5;
        }
        else if(b == 1){
            answer = 1;
            break;
        }
        else{
            if(b != 1){
                answer = 2;
                break;
            }
        }
    }
    return answer;
}