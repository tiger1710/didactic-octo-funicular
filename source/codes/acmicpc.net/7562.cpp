#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
using namespace std;
using point = pair<int, int>;

point operator+(const point& A, const point& B) {	
    return point(A.first + B.first, A.second + B.second);	
}

istream& operator>>(istream& cin, point& p) {
    cin >> p.first >> p.second;
    return cin;
}

bool isSafe(const point& p, const int& L) {
    return 0 <= p.first and p.first < L and 0 <= p.second and p.second < L;
}

int bfs(const point& from, const point& to, const int& L) {
    static const point diff[8] = { point(-1, -2), point(-2, -1), point(-2, 1), point(-1, 2),
                                point (1, 2), point(2, 1), point(2, -1), point(1, -2) };

    vector<vector<int>> visited(L, vector<int>(L, 0));
    queue<point> q;
    visited[from.first][from.second] = 1;
    q.push(from);

    while (not q.empty()) {
        point cur = q.front(); q.pop();
        if (cur == to) return visited[cur.first][cur.second] - 1;
        for (const point& d : diff) {
            point next = cur + d;
            if (isSafe(next, L) and
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
    cin.tie(NULL);

    int testCase; cin >> testCase;

    for (int tc = 0; tc < testCase; tc++) {
        int L; cin >> L;
        point from, to; cin >> from >> to;
        cout << bfs(from, to, L) << endl;
    }



    return 0;
}