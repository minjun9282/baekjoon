#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

int N;
vector<int> ope_idx;
vector<vector<int>> combination;

void dfs(int idx, vector<int>& picked, int maxPick) {
    if (picked.size() <= maxPick)
        combination.push_back(picked);
        
    if (picked.size() == maxPick || idx >= ope_idx.size()) {
        return;
    }

    if (picked.empty() || idx - picked.back() > 1) {
        picked.push_back(idx);
        dfs(idx + 1, picked, maxPick);
        picked.pop_back();
    }
    
    dfs(idx + 1, picked, maxPick);
}

int calculate(vector<int> num, vector<char> ope) {
    int result = num[0];
    for (int i = 0; i < ope.size(); i++) {
        if (ope[i] == '+'){
            result += num[i+1];
        }
        else if (ope[i] == '*'){
            result *= num[i+1];
        }
        else if (ope[i] == '/'){
            result /= num[i+1];
        }
        else{
            result -= num[i+1];
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    string expression;
    cin >> expression;

    vector<int> num;
    vector<char> ope;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) num.push_back(expression[i] - '0');
        else ope.push_back(expression[i]);
    }

    int maxPick = (N - 1) / 2;
    for (int i = 0; i < ope.size(); i++)
        ope_idx.push_back(i);

    vector<int> picked;
    dfs(0, picked, maxPick);

    int max_result = INT_MIN;

    for (const auto& comb : combination) {
        vector<int> tmp_num = num;
        vector<char> tmp_ope = ope;
        vector<bool> used(tmp_ope.size(), false);

        // 괄호 먼저 계산
        for (int idx : comb) {
            if (used[idx]) continue;

            int res;
            if (tmp_ope[idx] == '+'){
                res = tmp_num[idx] + tmp_num[idx+1];
            }
            else if (tmp_ope[idx] == '*'){
                res = tmp_num[idx] * tmp_num[idx+1];
            }
            else if (tmp_ope[idx] == '/'){
                res = tmp_num[idx] / tmp_num[idx+1];
            }
            else{
                res = tmp_num[idx] - tmp_num[idx+1];
            }
            
            tmp_num[idx] = res;
            tmp_num[idx + 1] = INT_MIN; 
            tmp_ope[idx] = '#';
            used[idx] = true;
        }

        // 마킹된 값 제거
        vector<int> final_num;
        vector<char> final_ope;
        for (int i = 0; i < tmp_num.size(); i++) {
            if (tmp_num[i] != INT_MIN) final_num.push_back(tmp_num[i]);
        }
        for (int i = 0; i < tmp_ope.size(); i++) {
            if (tmp_ope[i] != '#') final_ope.push_back(tmp_ope[i]);
        }

        int result = calculate(final_num, final_ope);
        max_result = max(max_result, result);
    }

    cout << max_result << '\n';
    return 0;
}
