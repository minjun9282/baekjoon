#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int cal_dist(pair<int, int> house, pair<int, int> chicken){ //집이랑 치킨집 사이 거리 구하는 함수
    int dist;
    dist = abs(house.first - chicken.first) + abs(house.second - chicken.second);
    return dist;
}

vector<pair<int, int>> house; //집 좌표 모아놓은 벡터
vector<pair<int, int>> chicken;//치킨집 좌표 모아놓은 벡터
vector<int> selected; //선택된 치킨집 인덱스
int min_result = INT_MAX;

void cal_chicken_dist(){
    int current_result = 0;
    
    for (const auto& h : house){
        int min_dist = INT_MAX;
        for (int idx: selected){
            min_dist = min(min_dist, cal_dist(h, chicken[idx]));
        }
        current_result += min_dist;
    }
    min_result = min(min_result, current_result);
}

void select_chicken(int start, int count, int M){ //M개 치킨집 고르는 조합에 백트래킹 이용
    if (count == M){
        cal_chicken_dist();
        return;
    }
    
    for (int i = start; i < chicken.size(); i++){
        selected.push_back(i);
        select_chicken(i+1, count+1, M);
        selected.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int building;
            cin >> building;
            if (building == 1){
                house.push_back(make_pair(i, j));
            }
            else if (building == 2){
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    select_chicken(0, 0, M);
    cout << min_result << '\n';
    
    return 0;
}