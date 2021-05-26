#include <iostream>
using namespace std;

// 원소의 개수가 n인 배열 S에 x가 있는지 순차적으로 검색하는 알고리즘. (sequential search algorithm)

void seqsearch(int n, const int S[], int x, int& location);
// S와 x의 데이터 타입을 int가 아닌 keytype으로 포괄적으로 설정 가능하고 location의 데이터 타입도 index로 표현가능하지만 구현을 위해 int로 통일하여 표현함.

int main(){
    int location;
    int S[10] = {3, 2, 13, 22, 33, 521, 7, 8, 6, 5};
    seqsearch(10, S, 2, location); cout << location << '\n';
    seqsearch(10, S, 521, location); cout << location << '\n';
    seqsearch(10, S, 9, location); cout << location << '\n';
    seqsearch(10, S, 222, location); cout << location << '\n';
    seqsearch(10, S, 5, location); cout << location << '\n';

    return 0;
}

void seqsearch(int n, const int S[], int x, int& location){
    location = 0; //C++에서 배열의 index는 0부터 시작.
    while(location < n && S[location]!= x){
        location++;
    }
    if(location >= n){
        location = -1; // x가 S에 포함되지 않을 경우 location의 값을 -1로 변경함.
    }
}
