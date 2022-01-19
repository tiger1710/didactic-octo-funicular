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

string map[50];
bool visited[50][50];
int R, C;
int m;
point d[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };

bool condition(const point& p) {
    return 0 <= p.first and p.first < R and 0 <= p.second and p.second < C and
        not visited[p.first][p.second] and
        map[p.first][p.second] == 'L';
}

void bfs(const point& s) {
    memset(visited, false, sizeof(visited));
    queue<point> q;
    q.push(s); visited[s.first][s.second] = true;

    int dist = 0;
    while (not q.empty()) {
        int qSize = q.size();
        REP (i, 0, qSize) {
            point curr = q.front(); q.pop();
            for (const point& diff : d) {
                point next = point(curr.first + diff.first, curr.second + diff.second);
                if (condition(next)) {
                    q.push(next);
                    visited[next.first][next.second] = true;
                }
            }
        }
        dist++;
    }
    m = max(m, dist);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    
    REP (r, 0, R) {
        cin >> map[r];
    }

    REP (r, 0, R) {
        REP (c, 0, C) {
            if (map[r][c] == 'L') {
                bfs(point(r, c));
            }
        }
    }
    
    cout << m - 1 << endl;


    return 0;
}
