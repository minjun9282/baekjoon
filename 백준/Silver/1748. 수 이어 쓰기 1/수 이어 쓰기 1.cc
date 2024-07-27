#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> vec(9, -1);
    int sum = 0;
    int temp = N;
    int i = 0;
    while (temp > 0){
        vec[i] = temp % 10;
        temp = temp / 10;
        i++;
    }
    i = 0;
    while(i < 9){
        if (vec[8] == 1){
            sum = 788888898;
            break;
        }
        if (vec[i+1] != -1){
            sum += (i+1) * pow(10, i) * 9;
        }
        else{
            sum += (N - pow(10, i) + 1) * (i + 1);
            break;
        }
        i++;
    }
    
    cout << sum << '\n';
    
    return 0;
}