#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)
#define point pair<int, int>

vector<vector<int> > graph;
vector<bool> visited;

void dfs(int cur) {
    visited[cur] = true;
    cout << cur + 1 << ' ';
    
    for (auto& next : graph[cur]) {
        if (not visited[next]) {
            dfs(next);
        }
    }

}

void bfs(const int& start) {
    queue<int> q;
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
    graph = vector<vector<int> >(N);
    visited = vector<bool>(N, false);

    for (int edge = 0; edge < M; edge++) {
        int u, v; cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    for (auto& g : graph) {
        sort(g.begin(), g.end());
    }

    dfs(V);
    cout << endl;

    fill(visited.begin(), visited.end(), false);
    bfs(V);
    cout << endl;
    
    return 0;
}