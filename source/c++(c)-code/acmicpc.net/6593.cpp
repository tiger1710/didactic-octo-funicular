#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

using Point = struct Point {
    int l, r, c;
};

int L, R, C;
Point start;
vector<vector<vector<char> > > building;
vector<vector<vector<int> > > visited;

bool isSafe(const Point& p) {
    return
        0 <= p.l and p.l < L and
        0 <= p.r and p.r < R and
        0 <= p.c and p.c < C;
}

bool escaped(const Point& p) {
    return building[p.l][p.r][p.c] == 'E';
}

int bfs(void) {
    static Point diff[6] = { { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, -1 }, { 0, 0, 1 }, { 1, 0, 0 }, { -1, 0 ,0 } };
    queue<Point> q;
    q.push(start);
    visited[start.l][start.r][start.c] = 1;

    while (not q.empty()) {
        Point curr = q.front(); q.pop();
        if (escaped(curr)) return visited[curr.l][curr.r][curr.c];
        
        for (const Point& d : diff) {
            Point next = { curr.l + d.l, curr.r + d.r, curr.c + d.c };
            if (
                isSafe(next) and
                building[next.l][next.r][next.c] not_eq '#' and
                not visited[next.l][next.r][next.c]
            ) {
                visited[next.l][next.r][next.c] = visited[curr.l][curr.r][curr.c] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while (true) {
        cin >> L >> R >> C;
        if (L == 0 and R == 0 and C == 0) break;
        building = vector<vector<vector<char> > >(L, vector<vector<char> >(R, vector<char>(C)));
        visited = vector<vector<vector<int> > >(L, vector<vector<int> >(R, vector<int>(C, 0)));

        REP (l, 0, L)
            REP (r, 0, R) {
                string str; cin >> str;
                REP (c, 0, C) {
                    building[l][r][c] = str[c];
                    if (str[c] == 'S') ::start = Point { l, r, c };
                }
            }

        int ans = bfs();
        if (ans not_eq -1) cout << "Escaped in " << ans - 1 << " minute(s)." << endl;
        else cout << "Trapped!" << endl;
    }
    

    return 0;
}
