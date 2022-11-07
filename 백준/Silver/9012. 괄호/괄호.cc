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
        cin.getline(ps, 51);
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
        while(!vps.empty()){
            vps.pop();
        }
        VPS = true;
        j = 0;
        i++;
    }

    return 0;
}