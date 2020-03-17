#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
#define point pair<int, int>
using namespace std;

int N, M;

point operator+(const point& A, const point& B) {
    return point(A.first + B.first, A.second + B.second);
}

bool isSafe(const point& p) {
    return 0 <= p.first and p.first < N and 0 <= p.second and p.second < M;
}

bool isWay(const vector<vector<int>>& maze, const point& p) {
    return maze[p.first][p.second];
}

bool visited(const vector<vector<int>>& visit, const point& p) {
    return visit[p.first][p.second];
}

int& get(vector<vector<int>>& arr, point p) {
    return arr[p.first][p.second];
}

int bfs(vector<vector<int>>& maze, vector<vector<int>>& visit) {
    const point diff[4] = { point(1, 0), point(-1, 0), point(0, -1), point(0, 1) };
    const point fin = { N - 1, M - 1 };

    queue<point> q;
    q.push(point(0, 0));
    get(visit, point(0, 0)) = 1;

    while (not q.empty()) {
        point cur = q.front(); q.pop();
        if (cur == fin) return visit[cur.first][cur.second];

        for (auto& d : diff) {
            point next = cur + d;
            if (isSafe(next) and isWay(maze, next) and not visited(visit, next)) {
                get(visit, next) = get(visit, cur) + 1;
                q.push(next);
            }
        }

    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin >> N >> M; cin.ignore();
    vector<vector<int>> maze(N, vector<int>(M));
    vector<vector<int>> visit(N, vector<int>(M, 0));

    for (auto& i: maze) {
        for (auto& k : i) {
            k = cin.get() - '0';
        }
        cin.ignore();
    }

    cout << bfs(maze, visit) << endl;

    return 0;
}