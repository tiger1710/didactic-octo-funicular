#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

int F, S, G, U, D;

bool isSafe(const int& pos) {
    return 0 < pos and pos < F + 1;
}

int bfs(void) {
    vector<int> visited(F + 1, 0);
    queue<int> q;
    q.push(S); visited[S] = 1;

    while (not q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == G) return visited[curr];
        int nextPos[2] = { curr - D, curr + U };
        
        for (const int& next : nextPos) {
            if (isSafe(next) and
                not visited[next]) {
                q.push(next);
                visited[next] = visited[curr] + 1;
            }
        }
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> F >> S >> G >> U >> D;
    int m = bfs();

    if (m == -1) {
        cout << "use the stairs" << endl;
    } else {
        cout << m - 1 << endl;
    }


    return 0;
}