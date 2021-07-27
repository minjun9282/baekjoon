#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    int* stack = new int[N];
    int i = 0;
    int point = -1;
    int temp;
    long long int sum = 0;

    while (i < N) {
        cin >> temp;
        if (temp != 0) {
            point++;
            stack[point] = temp;
            sum += stack[point];
        }
        else{
            sum -= stack[point];
            point--;
        }
        i++;
    }
    cout << sum << '\n';
    delete[] stack;

    return 0;
}