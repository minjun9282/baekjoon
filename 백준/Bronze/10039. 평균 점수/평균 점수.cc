#include <iostream>
using namespace std;

int main(){
    int i = 0;
    int result = 0;
    int record;
    while(i < 5){
        cin >> record;
        if(record < 40){
            result += 40;
        }
        else{
            result += record;
        }
        i++;
    }
    cout << result / 5 << '\n';

    return 0;
}