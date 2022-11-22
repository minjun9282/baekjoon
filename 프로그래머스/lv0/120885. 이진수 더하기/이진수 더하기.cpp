#include <string>
#include <cmath>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) {
    long long int answer = 0;
    int bin1_decimal = 0;
    int bin2_decimal = 0;
    int answer_decimal = 0;
    for(int i = 0; i < bin1.size(); i++){
        if(bin1[i] == '1'){
            bin1_decimal += pow(2, bin1.size() - 1 - i);
        }
    }
    for(int j = 0; j < bin2.size(); j++){
        if(bin2[j] == '1'){
            bin2_decimal += pow(2, bin2.size() - 1 - j);
        }
    }
    answer_decimal = bin1_decimal + bin2_decimal;
    vector<int> ans;
    int rem, quo = answer_decimal;
    while(quo != 1){
        rem = quo % 2;
        quo = quo / 2;
        ans.push_back(rem);
        if(quo == 1){
            ans.push_back(quo);
        }
        else if(quo == 0){
            break;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        answer += pow(10, i) * ans[i];
    }
    string s;
    s = to_string(answer);

    return s;
}