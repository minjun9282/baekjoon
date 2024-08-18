#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int temp = v.back();
    int pages = 1;
    int j = N - 2;
    while(j >= 0){
        if (v[j] * 2 <= temp){
            temp = v[j];
            pages += 1;
        }
        j--;
    }
    cout << pages << '\n';
    
    return 0;
}