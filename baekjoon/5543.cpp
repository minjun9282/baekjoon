#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int burger = 2000;
    int beverage = 2000;
    int i = 0;
    int temp;
    while(i < 3){
        cin >> temp;
        if(temp < burger){
            burger = temp;
        }
        i++;
    }
    int j = 0;
    while(j < 2){
        cin >> temp;
        if(temp < beverage){
            beverage = temp;
        }
        j++;
    }
    cout << burger + beverage - 50 << '\n';

    return 0;
}