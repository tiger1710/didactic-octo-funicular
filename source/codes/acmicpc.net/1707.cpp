#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define point pair<int, int>
using namespace std;

int V, E;

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<char>& marking, int cur) {
    bool res;
    visited[cur] = true;

    for (auto& next : graph[cur]) {
        if (not visited[next]) {
            marking[next] = !marking[cur];
            res = dfs(graph, visited, marking, next);
            if (!res) return res;
        }
        if (visited[next] and marking[cur] == marking[next]) return false;
    }

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    int K; cin >> K;
    
    for (int test = 0; test < K; test++) {
        cin >> V >> E;
        vector<vector<int>> graph(V);
        vector<bool> visited(V, false);
        vector<char> marking(V);
        for (int edge = 0; edge < E; edge++) {
            int u, v; cin >> u >> v;
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        
        bool res;
        for (int i = 0; i < V; i++) {
            if (not visited[i]) {
                marking[i] = 0;
                res = dfs(graph, visited, marking, i);
                if (!res) break;
            }
        }

        cout << (res ? "YES" : "NO") << endl;

    }


    return 0;
}
