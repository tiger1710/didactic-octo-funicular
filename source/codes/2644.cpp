#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
#define point pair<int, int>
using namespace std;

int bfs(vector<vector<int>>& people, const int& from, const int& to) {
    queue<int> q;
    vector<int> visit(people.size());

    q.push(from);
    visit[from] = 1;

    while (not q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == to) return visit[cur] - 1;

        for (int& next : people[cur]) {
            if (not visit[next]) {
                q.push(next);
                visit[next] = visit[cur] + 1;
            }
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int from, to; cin >> from >> to; from--, to--;
    int m; cin >> m;

    vector<vector<int>> people(n);

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        people[x - 1].push_back(y - 1);
        people[y - 1].push_back(x - 1);
    }

    cout << bfs(people, from, to) << endl;

    return 0;
}