#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

bool check_lucky(string s){
    for (int i = 1; i < s.size(); i++){
        if (s[i] == s[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    int count = 0;
    do{
        string s = "";
        for (int i = 0; i < S.size(); i++){
            s += S[i];
        }
        if (check_lucky(s)){
            count += 1;
        }
    }while (next_permutation(S.begin(), S.end()));
    
    cout << count << '\n';
    
    return 0;
}