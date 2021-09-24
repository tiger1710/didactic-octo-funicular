#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

using point = tuple<int, int, char>;

vector<string> map;
vector<vector<vector<int> > > visited;
const int dr[4] = { 1, -1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };
int N, M;

void input(void) {
    cin >> N >> M;
    map.resize(N);
    visited = vector<vector<vector<int> > >(N, vector<vector<int> >(M, vector<int>(2, false)));
    for (string& row : map) {
        cin >> row;
    }
}

bool condition(const point& p) {
    int r, c; bool b; tie(r, c, b) = p;
    return (0 <= r and r < N and 0 <= c and c < M) and
        not visited[r][c][b] and map[r][c] == '0';
}

bool break_condition(const point& p) {
    int r, c; bool b; tie(r, c, b) = p;
    return (0 <= r and r < N and 0 <= c and c < M) and
        not visited[r][c][1] and map[r][c] == '1';
}

int bfs(void) {
    queue<point> q;
    q.push(make_tuple(0, 0, 0));
    visited[0][0][0] = 1;

    while (not q.empty()) {
        const point curr = q.front(); q.pop();
        int r, c, b; tie(r, c, b) = curr;
        if (r == N - 1 and c == M - 1) {
            return visited[r][c][b];
        }
        /*
        cout << "r, c, b: " << r << ", " << c << ", " << b << endl;
        cout << "visited[r][c][b]: " << visited[r][c][b] << endl;
        */

        REP (i, 0, 4) {
            const int nextr = r + dr[i], nextc = c + dc[i], nextb = b;

            point next(nextr, nextc, nextb);
            //cout << "nextr, nextc, nextb: " << nextr << ", " << nextc << ", " << nextb << endl;
            if (condition(next)) {
                q.push(next);
                visited[nextr][nextc][nextb] = visited[r][c][b] + 1;
            }
            if (not nextb and break_condition(next)) {
                q.push(point(nextr, nextc, 1));
                visited[nextr][nextc][1] = visited[r][c][b] + 1;
            }
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    cout << bfs() << endl;

    return 0;
}
