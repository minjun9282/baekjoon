#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, change, num_c;
    cin >> N;
    change = 1000 - N;
    num_c = 0;
    int arr[6] = {500, 100, 50, 10, 5, 1};
    int i = 0;
    while(change != 0){
        if(arr[i] <= change){
            num_c++;
            change = change - arr[i];
        }
        else{
            i++;
        }
    }
    cout << num_c << '\n';

    return 0;
}