#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string color[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    long long int resis[10][2] ={
        {0, 1},
        {1, 10},
        {2, 100},
        {3, 1000},
        {4, 10000},
        {5, 100000},
        {6, 1000000},
        {7, 10000000},
        {8, 100000000},
        {9, 1000000000}
    };
    string first, second, third;
    cin >> first >> second >> third;
    long long int fir, sec, thr;
    
    for(int i = 0; i < 10; i++){
        if(first == color[i]){
            fir = resis[i][0];
        }
        if(second == color[i]){
            sec = resis[i][0];
        }
        if(third == color[i]){
            thr = resis[i][1];
        }
    }
    long long int result;
    result = fir * 10 * thr + sec * thr;
    cout << result << '\n';

    return 0;
}