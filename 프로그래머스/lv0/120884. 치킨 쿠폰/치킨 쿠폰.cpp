#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int quo, rem;
    while(chicken > 9){
        quo = chicken / 10;
        rem = chicken % 10;
        answer += quo;
        chicken = quo + rem;
    }
    
    return answer;
}
    