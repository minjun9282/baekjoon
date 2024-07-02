#include <iostream>
#include <string>
using namespace std;

int stack[10000];
int stack_size = 0;

void push(int X){
        stack[stack_size] = X;
        stack_size += 1;
    }

int pop(){
    if (stack_size > 0){
        stack_size -= 1;
        return stack[stack_size];
    }
    else{
        return -1;
    }
    
}

int size(){
    return stack_size;
}

int empty(){
    if (stack_size == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int top(){
    if (stack_size != 0){
        return stack[stack_size-1];
    }
    else{
        return -1;
    }
}

int main(){
    int N;
    int X;
    string command;
    
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> command;
        if (command == "push"){
            cin >> X;
            push(X);
        }
        else if (command == "pop"){
            cout << pop() << '\n';
        }
        else if (command == "size"){
            cout << size() << '\n';
        }
        else if (command == "empty"){
            cout << empty() << '\n';
        }
        else{
            cout << top() << '\n';
        }
    }
    
    return 0;
}