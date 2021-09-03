#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

vector<vector<int> > com;
vector<bool> visited;

int dfs(const int& curr) {
    int cnt = 1;
    visited[curr] = true;

    for (const int& next : com[curr])
        if (not visited[next])
            cnt += dfs(next);
    
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    int e; cin >> e;

    com = vector<vector<int> >(n);
    visited = vector<bool>(n, false);

    REP(i, 0, e) {
        int u, v; cin >> u >> v;
        com[u - 1].push_back(v - 1);
        com[v - 1].push_back(u - 1);
    }

    cout << dfs(0) - 1 << endl;


    return 0;
}