#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    int* stack = new int[N];
    int i = 0;
    int point = -1;
    string order;
    int number;


    while(i < N){
        cin >> order;
        if(order == "push"){
            cin >> number;
            point++;
            stack[point] = number;
        }
        else if(order == "pop"){
            if(point > -1){
                cout << stack[point] << '\n';
                point--;
            }
            else{
                cout << -1 << '\n';
            }
        }
        else if(order == "size"){
            cout << point + 1 << '\n';
        }
        else if(order == "empty"){
            if(point > -1){
                cout << 0 << '\n';
            }
            else{
                cout << 1 << '\n';
            }
        }
        else if(order == "top"){
            if(point > -1){
                cout << stack[point] << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
    i++;
    }
    
    delete[] stack;

    return 0;
}