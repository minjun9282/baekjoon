#include <iostream>
#include <string>
using namespace std;

int main(){
    int x,y;
    int result = 0;
    cin >> x >> y;
    if(x == 1){
        result += y;
    }
    else if(x == 2){
        result = result + 31 + y;
    }
    else if(x == 3){
        result = result + 31 + 28 + y;
    }
    else if(x == 4){
        result = result + 31 * 2 + 28 + y;
    }
    else if(x == 5){
        result = result + 31 * 2 + 28 + 30 + y;
    }
    else if(x == 6){
        result = result + 31 * 3 + 28 + 30 + y;
    }
    else if(x == 7){
        result = result + 31 * 3 + 28 + 30 * 2 + y;
    }
    else if(x == 8){
        result = result + 31 * 4 + 28 + 30 * 2 + y;
    }
    else if(x == 9){
        result = result + 31 * 5 + 28 + 30 * 2 + y;
    }
    else if(x == 10){
        result = result + 31 * 5 + 28 + 30 * 3 + y;
    }
    else if(x == 11){
        result = result + 31 * 6 + 28 + 30 * 3 + y;
    }
    else if(x == 12){
        result = result + 31 * 6 + 28 + 30 * 4 + y;
    }

    int rem = result % 7;
    string day;
    if(rem == 1){
        cout << "MON" << '\n';
    }
    else if(rem == 2){
        cout << "TUE" << '\n';
    }
    else if(rem == 3){
        cout << "WED" << '\n';
    }
    else if(rem == 4){
        cout << "THU" << '\n';
    }
    else if(rem == 5){
        cout << "FRI" << '\n';
    }
    else if(rem == 6){
        cout << "SAT" << '\n';
    }
    else{
        cout << "SUN" << '\n';
    }

    return 0;
}