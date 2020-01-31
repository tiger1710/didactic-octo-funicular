#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(vector<int>& cycle, vector<bool>& visitied, int cur) {
    visitied[cur] = true;
    int next = cycle[cur];
    if (not visitied[next]) {
        dfs(cycle, visitied, next);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        vector<int> cycle(N);
        vector<bool> visited(N);
        for (int& k : cycle) {
            cin >> k;
            k--;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (not visited[i]) {
                cnt++;
                dfs(cycle, visited, i);
            }
        }

        cout << cnt << endl;
    }


    return 0;
}
