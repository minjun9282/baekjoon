#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    vector<int> num;
    int i = 0;
    while(i < numbers.size()){
        if(numbers[i] == 'o'){
            num.push_back(1);
            i += 3;
        }
        else if(numbers[i] == 't'){
            if(numbers[i + 1] == 'w'){
                num.push_back(2);
                i += 3;
            }
            else{
                num.push_back(3);
                i += 5;
            }
        }
        else if(numbers[i] == 'f'){
            if(numbers[i + 1] == 'o'){
                num.push_back(4);
                i += 4;
            }
            else{
                num.push_back(5);
                i += 4;
            }
        }
        else if(numbers[i] == 's'){
            if(numbers[i + 1] == 'i'){
                num.push_back(6);
                i += 3;
            }
            else{
                num.push_back(7);
                i += 5;
            }
        }
        else if(numbers[i] == 'e'){
            num.push_back(8);
            i += 5;
        }
        else if(numbers[i] == 'n'){
            num.push_back(9);
            i += 4;
        }
        else{
            num.push_back(0);
            i += 4;
        }
    }
    for(int i = 0; i < num.size(); i++){
        answer += num[i] * pow(10, num.size() - i - 1);
    }
    return answer;
}