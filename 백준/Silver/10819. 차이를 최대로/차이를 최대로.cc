#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int abs_cal(vector<int> numbers);

int main(){
    int N, num, max_result;
    vector<int> numbers;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        numbers.push_back(num);
    }
    max_result = abs_cal(numbers);
    sort(numbers.begin(), numbers.end());
    do {
        if(abs_cal(numbers) > max_result){
            max_result = abs_cal(numbers);
        };
    } while(next_permutation(numbers.begin(), numbers.end()));
    cout << max_result << '\n';

    return 0;
}

int abs_cal(vector<int> numbers){
    int result = 0;
    for(int i = 0; i < numbers.size() - 1; i++){
        result += abs(numbers[i] - numbers[i + 1]);
    }
    return result;
}