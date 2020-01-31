#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>
#include <string>
#define endl '\n'
#define point pair<int, int>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur) {
    visited[cur] = true;
    cout << cur + 1 << ' ';
    
    for (auto& next : graph[cur]) {
        if (not visited[next]) {
            dfs(graph, visited, next);
        }
    }

}

void bfs(vector<vector<int>>& graph, const int& start) {
    queue<int> q;
    vector<bool> visited(graph.size());
    q.push(start); visited[start] = true;

    while (not q.empty()) {
        int cur = q.front();
        cout << cur + 1 << ' ';
        q.pop();
        for (auto& next : graph[cur]) {
            if (not visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);
    int N, M, V; cin >> N >> M >> V; V--;

    vector<vector<int>> graph(N);
    vector<bool> visited(N);
    for (int edge = 0; edge < M; edge++) {
        int u, v; cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    for (auto& g : graph) {
        sort(g.begin(), g.end());
    }

    dfs(graph, visited, V);
    cout << endl;
    bfs(graph, V);
    cout << endl;
    


    return 0;
}