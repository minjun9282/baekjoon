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
    cin.ignore(); // cin은 '\n'를 처리하지 않고 입력버퍼에 남겨둔다. geline은 '\n'를 입력버퍼에서 가져와서 처리한다. 따라서 여기서 cin.ignore()가 필요
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
            else if(input[j] == '\0'){ //여기서 '\n'이 아닌 '\0'로 잡아야 함. 문자열 끝에는 '\0'가 들어감.
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

/*
cin과 Getline 사용시 버퍼 유무
1. cin으로 입력받을 경우, 버퍼에 '\n'이 남는다.

2. cin 다음 입력을 cin으로 받을경우, 전 버퍼에 있던 공백 및 개행문자를 무시하기 때문에 버퍼를 굳이 비워줄 필요가 없다.

3. cin 다음 입력을 getline으로 받을경우, 전 버퍼에 있던 공백 및 개행문자를 포함해서 입력받기 때문에 버퍼를 지워주는 작업이 필요하다.

4. getline 다음 입력을 getline으로 받을경우, getline은 '\n' 문자를 버퍼에 포함시키기 않기때문에 버퍼를 비워줄 필요가 없다.
*/