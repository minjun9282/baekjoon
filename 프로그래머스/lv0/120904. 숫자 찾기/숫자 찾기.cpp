#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    int total_cipher, k_cipher, cipher = 1;
    k_cipher = 0;
    while(true){
        if(num == 0){
            total_cipher = cipher;
            break;
        }
        if(num % 10 == k){
            k_cipher = cipher;
        }
        num = num / 10;
        cipher++;
    }
    if(k_cipher == 0){
        answer = -1;    
    }
    else{
        answer = total_cipher - k_cipher;
    }
    return answer;
}