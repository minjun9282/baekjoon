#include <iostream>
#include <cmath>
using namespace std;

// 원소가 n개인 정렬된 배열 S에서 원소 x를 찾으시오.

void binsearch(int n, const int S[], int x, int &location);
void binsearch2(int n, const int* S, int x, int &location);

int main(){
    int arr[10] = {1, 4, 7, 23, 32, 36, 55, 58, 73, 88};
    int location;
    binsearch(10, arr, 99, location);
    cout << location << '\n';

    binsearch2(10, arr, 23, location);
    cout << location << '\n';

    return 0;
}

void binsearch(int n, const int S[], int x, int &location){
    int low, high, mid;
    low = 0; high = n - 1;
    location = -1;
    while(low <= high && location == -1){
        mid = floor((low + high) / 2);
        if(x == S[mid]){
            location = mid;
        }
        else if(x < S[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
}

void binsearch2(int n, const int* S, int x, int &location){
    int low, high, mid;
    low = 0; high = n - 1;
    location = -1;
    while(low <= high && location == -1){
        mid = floor((low + high) / 2);
        if(x == S[mid]){
            location = mid;
        }
        else if(x < S[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
}