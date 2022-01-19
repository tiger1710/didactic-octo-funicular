#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

using point = pair<int, int>;

int N, cnt = 1, m = 123456789;
int map[100][100];
bool visited[100][100];
point d[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };

bool condition(const point& p) {
    return 0 <= p.first and p.first < N and 0 <= p.second and p.second < N and
        not visited[p.first][p.second] and
        map[p.first][p.second];
}

void dfs(const point& curr) {
    visited[curr.first][curr.second] = true;
    map[curr.first][curr.second] = cnt;

    for (const point& diff : d) {
        point next = point(curr.first + diff.first, curr.second + diff.second);
        if (condition(next)) {
            dfs(next);
        }
    }
}

void bfs(const int& n) {
    memset(visited, false, sizeof(visited));
    queue<point> q;
    REP (r, 0, N) {
        REP (c, 0, N) {
            if (map[r][c] == n) {
                q.push(point(r, c));
                visited[r][c] = true;
            }
        }
    }

    int bridge = 0;
    while (not q.empty()) {
        int qSize = q.size();
        REP (i, 0, qSize) {
            point curr = q.front(); q.pop();
            for (const point& diff : d) {
                point next = point(curr.first + diff.first, curr.second + diff.second);
                if (0 <= next.first and next.first < N and
                    0 <= next.second and next.second < N and
                    not visited[next.first][next.second]) {
                    if (map[next.first][next.second] not_eq 0 and
                        map[next.first][next.second] not_eq n) {
                        m = min(m, bridge);
                        return;
                    }
                    q.push(next);
                    visited[next.first][next.second] = true;
                }
            }
        }
        bridge++;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    REP (r, 0, N) {
        REP (c, 0, N) {
            cin >> map[r][c];
        }
    }

    REP (r, 0, N) {
        REP (c, 0, N) {
            if (not visited[r][c] and map[r][c]) {
                dfs(point(r, c));
                cnt++;
            }
        }
    }

    REP (i, 1, cnt) {
        bfs(i);
    }

    cout << m << endl;

    return 0;
}
