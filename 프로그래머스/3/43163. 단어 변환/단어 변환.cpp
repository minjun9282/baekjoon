#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, vector<string>> graph;
map<string, bool> visited;

bool one_chars_diff(string ref, string tar) {
    int num_diff = 0;
    for (int i = 0; i < ref.size(); i++) {
        if (ref[i] != tar[i]) {
            num_diff += 1;
        }
    }
    return num_diff == 1;
}

void make_graph(string begin, string target, vector<string> words, map<string, vector<string>>& graph, map<string, bool>& visited) {
    if (find(words.begin(), words.end(), target) == words.end()) return;
    
    vector<string> all_words = words;
    all_words.push_back(begin);
    
    for (int i = 0; i < all_words.size() - 1; i++) {
        for (int j = i + 1; j < all_words.size(); j++) {
            if (one_chars_diff(all_words[i], all_words[j])) {
                graph[all_words[i]].push_back(all_words[j]);
                graph[all_words[j]].push_back(all_words[i]);
            }
        }
    }

    for (const auto& pair : graph) {
        visited[pair.first] = false;
    }
}

int bfs(string begin, string target) {
    queue<pair<string, int>> q;
    q.push({begin, 0});
    visited[begin] = true;
    
    while(!q.empty()){
        string cur = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (cur == target){
            return steps;
        }
        for (const auto& next: graph[cur]){
            if (!visited[next]){
                q.push({next, steps + 1});
                visited[next] = true;
            }
        }
        
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    make_graph(begin, target, words, graph, visited);
    return bfs(begin, target);
}