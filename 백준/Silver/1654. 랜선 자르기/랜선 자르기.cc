#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long K, N;
    cin >> K >> N;

    vector<long long> length(K);
    long long end = 0;
    for (int i = 0; i < K; i++){
        cin >> length[i];
        if (length[i] > end) end = length[i];
    }

    long long result;
    long long start = 1;

    while (start <= end){
        long long mid = (start + end) / 2;
        result = 0;

        for (int i = 0; i < K; i++){
            result += (length[i] / mid);
            if (result >= N){
                break;
            }
        }

        if (result >= N){
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }

    cout << end << '\n';
    
    return 0;
}
