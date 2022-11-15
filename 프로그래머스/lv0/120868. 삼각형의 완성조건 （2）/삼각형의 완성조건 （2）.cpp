#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int larger_num = (sides[0] > sides[1]) ? sides[0] : sides[1];
    int smaller_num = (sides[0] > sides[1]) ? sides[1] : sides[0];
    int start = larger_num - smaller_num + 1;
    int end = larger_num + smaller_num - 1;
    answer = end - start + 1;
    return answer;
}