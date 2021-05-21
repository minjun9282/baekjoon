#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 배열 A의 크기 N이 주어짐. (N은 50이하의 자연수.)
    int N;
    cin >> N;

    // 2. 배열 A의 원소 입력받기(동적 할당)
    int* array_A = new int[N];
    for(int i = 0; i < N; i++){
        cin >> array_A[i];
    }
    // 3. 수열 A를 비내림차순으로 만들도록 하는 수열 A의 index를 원소로 갖는 배열 P 생성
    int* array_P = new int[N];
    int low, high;
    low = 0;

    // 4. 결과 출력 및 동적 배열 A, P 해제
    for(int i = 0; i < N; i++){
        cout << array_P[i] << ' ';
    }
    cout << '\n';
    delete[] array_A;
    delete[] array_P;

    return 0;
}