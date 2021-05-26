#include <iostream>
#include <cmath>
using namespace std;

int binsearch(int low, int high, int* S, int x);

int main(){
    int S[7] = {2, 5, 7, 23, 45, 73, 89};
    cout << binsearch(0, 6, S, 45);

    return 0;
}

int binsearch(int low, int high, int* S, int x){
    int mid = floor((low + high) / 2);
    if(low > high){
        return -1;
    }
    else if(S[mid] == x){
        return mid;
    }
    else if(S[mid] < x){
        return binsearch(mid + 1, high, S, x);
    }
    else{
        return binsearch(low, mid - 1, S, x);
    }
}