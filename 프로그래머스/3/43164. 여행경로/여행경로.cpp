#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<string> answer;

void dfs(map<string, vector<string>> &graph, string node){
    while (!graph[node].empty()){
        string next = graph[node].front();
        graph[node].erase(graph[node].begin());
        dfs(graph, next);
    }
    answer.push_back(node);
}

vector<string> solution(vector<vector<string>> tickets) {
    map<string, vector<string>> graph;
    for (const auto& ticket : tickets){
        graph[ticket[0]].push_back(ticket[1]);
    }
    for (auto& pair : graph){
        sort(pair.second.begin(), pair.second.end());
    }
    dfs(graph, "ICN");
    reverse(answer.begin(), answer.end());
    
    return answer;
}