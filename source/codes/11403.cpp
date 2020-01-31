#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int way(vector<vector<int>>& G, vector<bool>& visited, int cur, int& target) {
    visited[cur] = true;
    if (G[cur][target]) return 1;
    for (int next = 0; next < G.size(); next++) {
        if (G[cur][next] and not visited[next]) {
            if (way(G, visited, next, target)) return 1;
        }
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    vector<vector<int>> G(N, vector<int>(N, 0));
    vector<bool> visited(N);

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> G[i][k];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cout << way(G, visited, i, k) << ' ';
            visited = vector<bool>(N);
        }
        cout << endl;
    }

    return 0;
}
