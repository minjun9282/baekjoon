#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    bool find = true;
    if (s.find('M') == string::npos){
        find = false;
    }
    if (s.find('O') == string::npos){
        find = false;
    }
    if (s.find('B') == string::npos){
        find = false;
    }
    if (s.find('I') == string::npos){
        find = false;
    }
    if (s.find('S') == string::npos){
        find = false;
    }
    
    if (find == true){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }
    
    return 0;
}