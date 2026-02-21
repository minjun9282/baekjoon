#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int start, int last, int target) {
    int low = start;
    int high = last;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int result = 0;
    for (int i = 0; i < N; i++) {
        int target_val = arr[i];

        for (int j = 0; j < N; j++) { //arr[i] = arr[j] + arr[found_idx]를 만족하는 경우의 수가 있으면 result++임
            if (i == j) {
                continue;
            }

            int diff = target_val - arr[j];

            int found_idx = binarySearch(arr, 0, N - 1, diff);

            if (found_idx != -1) {
                if (found_idx != i && found_idx != j) {
                    result++;
                    break;
                }
                else {
                    if (found_idx + 1 < N && arr[found_idx + 1] == diff && (found_idx + 1 != i && found_idx + 1 != j)) {//오른쪽에 같은 값 있는 경우
                        result++; 
                        break;
                    }
                    if (found_idx - 1 >= 0 && arr[found_idx - 1] == diff && (found_idx - 1 != i && found_idx - 1 != j)) {//왼쪽에 같은 값 있는 경우
                        result++; 
                        break;
                    }
                }
            }
        }
    }
    cout << result << '\n';
    return 0;
}
