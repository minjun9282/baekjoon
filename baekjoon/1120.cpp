/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string A, B;
    cin >> A >> B;
    int temp = 0;
    int max = 0;
    for(int i = 0; i < B.length() - A.length() + 1; i++){
        for(int j = 0; j < A.length(); j++){
            if(A[j] == B[i+j]){
                temp++;
            }
        }
        if(temp > max){
            max = temp;
        }
        temp = 0;
    }
    
    cout << A.length() - max << '\n';

    return 0;
}
