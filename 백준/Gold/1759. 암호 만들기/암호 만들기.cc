#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<char> c){
    int vowel = 0;
    int consonant = 0;
    for (int i = 0; i < c.size(); i++){
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u'){
            vowel++;
        }
        else{
            consonant++;
        }
    }
    if (vowel >= 1 && consonant >= 2){
        return true;
    }
    else{
        return false;
    }
}

int a[15];
bool c[15];
vector<char> character;

void go(int index, int start, int C, int L){
    if (index == L){
        vector<char> temp;
        for (int i = 0; i < L; i++){
            temp.push_back(character[a[i]]);
        }
        if (check(temp) == true){
            for (int i = 0; i < L; i++){
                cout << temp[i];
            }
            cout << '\n';
        }
        return;
    }
    for (int i = start; i < C; i++){
        if (c[i]){
            continue;
        }
        c[i] = true;
        a[index] = i;
        go(index + 1, i + 1, C, L);
        c[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int L, C;
    cin >> L >> C;
    character.resize(C);
    for (int i = 0; i < C; i++){
        cin >> character[i];
    }
    sort(character.begin(), character.end());
    go(0, 0, C, L);
    
    return 0;
}