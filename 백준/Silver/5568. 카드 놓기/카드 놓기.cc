#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n;
    cin >> k;
    vector<string> cards(n);
    set<string> int_set;
    
    for (int i = 0; i < n; i++){
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());
    
    do{
        string s = "";
        for (int i = 0; i < k; i++){
            s += cards[i];
        }
        int_set.insert(s);
    }while(next_permutation(cards.begin(), cards.end()));
    
    cout << int_set.size() << '\n';
    
    return 0;
}