#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
using namespace std;
using point = pair<int, int>;
vector<vector<int> > maze;
vector<vector<int> > visited;

int N, M;

point operator+(const point& A, const point& B) {
    return point(A.first + B.first, A.second + B.second);
}

bool isSafe(const point& p) {
    return 0 <= p.first and p.first < N and 0 <= p.second and p.second < M;
}

int bfs(void) {
    const point diff[4] = { point(1, 0), point(-1, 0), point(0, -1), point(0, 1) };
    const point fin = { N - 1, M - 1 };

    queue<point> q;
    q.push(point(0, 0));
    visited[0][0] = 1;

    while (not q.empty()) {
        point cur = q.front(); q.pop();
        if (cur == fin) return visited[cur.first][cur.second];

        for (auto& d : diff) {
            point next = cur + d;
            if (isSafe(next) and
                maze[next.first][next.second] and
                not visited[next.first][next.second]) {
                    visited[next.first][next.second] = visited[cur.first][cur.second] + 1;
                    q.push(next);
            }
        }
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin >> N >> M; cin.ignore();
    maze = vector<vector<int> >(N, vector<int>(M));
    visited = vector<vector<int> >(N, vector<int>(M, 0));

    for (auto& i: maze) {
        for (auto& k : i) {
            k = cin.get() - '0';
        }
        cin.ignore();
    }
    cout << bfs() << endl;

    return 0;
}