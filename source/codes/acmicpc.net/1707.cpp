#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

vector<int> visited;
vector<vector<int> > graph;
int V, E;
bool ans;

void input(void) {
    cin >> V >> E;
    graph = vector<vector<int> >(V);
    visited = vector<int>(V, -1);
    REP(i, 0, E) {
        int u, v; cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
}

bool dfs(const int& curr, const char& bi) {
    visited[curr] = bi;

    for (const int& next : graph[curr]) {
        if (visited[next] == -1) {
            if (not dfs(next, (bi + 1) & 1)) {
                return false;
            }
        } else if (visited[next] == bi)
            return false;
    }

    return true;
}

void calc(void) {
    REP(i, 0, V)
        if (visited[i] == -1) {
            ans = dfs(i, 0);
            if (not ans) return;
        }
}

void ouput(void) {
    cout << (ans ? "YES" : "NO") << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;
    while (K--) {
        input();
        calc();
        ouput();
    }
    

    return 0;
}
