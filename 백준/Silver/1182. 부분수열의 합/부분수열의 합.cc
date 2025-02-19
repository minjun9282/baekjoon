#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, S;
    cin >> N >> S;
    
    vector<int> numbers(N);
    for(int i = 0; i < N; i++){
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    
    int count = 0;
    
    for (int i = 1; i <= N; i++){
        vector<bool> mask(N, false);
        fill(mask.begin(), mask.begin() + i, true); //nCi에서 i개만 사용하기 위함
        
        do{
            int sum = 0;
            for (int i = 0; i < N; i++){
                if (mask[i]){
                    sum += numbers[i];
                }
            }
            if (sum == S){
                count++;
            }    
        }while(prev_permutation(mask.begin(), mask.end()));
    }
    cout << count << '\n';
    
    return 0;
}