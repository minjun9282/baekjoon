#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    bool VPS = true;
    cin >> T;
    cin.ignore();

    stack<char> vps;
    char ps[50];
    int i = 0;
    int j = 0;

    while(i < T){
        cin.getline(ps, 51); //여기서 문자열을 50개까지 받으려면 51을 써줘야함!
        while(true){
            if(ps[j] == '\0'){
                break;
            }
            else{
                if(ps[j] == '('){
                    vps.push('(');
                    j++;
                }
                else{
                    if(vps.size() == 0){
                        VPS = false;
                        break;
                    }
                    else{
                        if(vps.top() == '('){
                            vps.pop();
                            j++;
                        }
                    }
                }
            }
        }
        if(vps.size() == 0 && VPS == true){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
        // j = 0, vps 스택, bool 변수 VPS 초기화 해줘야함.

        /*
        for(int k = 0; k < vps.size(); k++){   //이방식으로 할 경우 예제 입력 1의 2번째 경우가 초기화가 제대로 안됨.
            vps.pop();
        }
        */

        while(!vps.empty()){
            vps.pop();
        }
        VPS = true;
        j = 0;
        i++;
    }

    return 0;
}