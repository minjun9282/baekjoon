#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, X, S;
    cin >> N;
    cin >> X >> S;
    int arr[N][2];
    for (int i = 0; i < N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    bool adventure = false;
    for (int i = 0; i < N; i++){
        if (arr[i][0] <= X && arr[i][1] > S){
            adventure = true;
        }
    }
    if (adventure){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }
    
    return 0;
}