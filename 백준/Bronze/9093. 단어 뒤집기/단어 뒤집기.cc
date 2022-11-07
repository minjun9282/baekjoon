#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    char input[1000];
    string s;
    stack<char> arr;

    cin >> T;
    cin.ignore();
    int i = 0;
    int j = 0;

    while(i < T){
        cin.getline(input, 1000);
        while(true){
            if(input[j] == ' '){
                j += 1;
                while(arr.size() != 0){
                    cout << arr.top();
                    arr.pop();
                }
                cout << ' ';

            }
            else if(input[j] == '\0'){
                while(arr.size() != 0){
                    cout << arr.top();
                    arr.pop();
                }
                cout << '\n';
                j = 0;
                break;
            }
            else{
                arr.push(input[j]);
                j++;
            }
        }
        i++;
    }

    return 0;
}