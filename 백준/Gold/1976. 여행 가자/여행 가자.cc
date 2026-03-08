#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

vector<vector<int>> road;
vector<int> plan;
set<int> route;
vector<bool> visited;

void find_bfs(vector<vector<int>>& road, set<int> &target, set<int> &route, int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		route.insert(curr);

		for (int next : road[curr]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	road.resize(N + 1);
	visited.resize(N + 1, false);
	plan.resize(M);
	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < N+1; j++) {
			int info;
			cin >> info;
			if (info == 1) {
				road[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> plan[i];
	}

	//중복된 원소 제거 및 오름차순 정렬
	set<int> target(plan.begin(), plan.end());
	
	find_bfs(road, target, route, *target.begin());
	
	//target이 route의 부분집합 이면 됨
	bool isSubset = includes(route.begin(), route.end(), target.begin(), target.end());
	if (isSubset) {
		cout << "YES" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}

	return 0;
}