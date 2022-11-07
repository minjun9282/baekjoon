#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int E, S, M;
    int result, i = 1;
    bool found = false;
    cin >> E >> S >> M;
    E = E % 15;
    S = S % 28;
    M = M % 19;
    while(!found){
        if((i % 15 == E) && (i % 28 == S)){
            if(i % 19 == M){
                found = true;
                result = i;
            }
        }
        i++;
    }
    cout << result << '\n';

    return 0;
}