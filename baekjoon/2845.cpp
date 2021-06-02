#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int L, P;
    cin >> L >> P;
    int num_participants[5];
    int i = 0;
    while(i < 5){
        cin >> num_participants[i];
        i++;
    }
    for(int i = 0; i < 5; i++){
        cout << num_participants[i] - L * P << " ";
    }
    cout << '\n';

    return 0;
}