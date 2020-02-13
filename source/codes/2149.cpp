#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
#define point pair<int, int>
using namespace std;

point operator+(const point& p1, const point& p2) {
    return point(p1.first + p2.first, p1.second + p2.second);
}

class Island {
private:
    int N;
    const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };
    vector<vector<int>> map;
    vector<vector<int>> visit;
    int ans = 987654321;

    int& visited(const point& p) {
        return visit[p.first][p.second];
    }
    int& pos(const point& p) {
        return map[p.first][p.second];
    }

    void dfs(const point& cur, const int& n) {
        visited(cur) = 1;
        pos(cur) = n;
        for (const point& d : diff) {
            point next = cur + d;
            if (isSafe(next)
                and pos(next)
                and not visited(next)) {
                dfs(next, n);
            }
        }
    }

    int marking(void) {
        int n = 1;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (pos(point(r, c)) and
                    not visited(point(r, c))) {
                    dfs(point(r, c), n++);
                }
            }
        }
        return n;
    }

    void init(queue<point>& q, const int& n) {
        q = queue<point>();
        visit = vector<vector<int>>(N, vector<int>(N));
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (pos(point(r, c)) == n) {
                    visited(point(r, c)) = 1;
                    q.push(point(r, c));
                }
            }
        }
    }
public:
    void solve(void) {
        input();
        clac();
        output();
    }

    bool isSafe(const point& p) {
        return 0 <= p.first and p.first < N and 0 <= p.second and p.second < N;
    }

    void input(void) {
        cin >> N;
        map = visit = vector<vector<int>>(N, vector<int>(N));
        for (auto& r : map) {
            for (auto& c : r) {
                cin >> c;
            }
        }
    }

    void clac(void) {
        int islands = marking();
        for (int i = 1; i < islands; i++) {

            queue<point> q; init(q, i);

            while (not q.empty()) {
                point cur = q.front(); q.pop();

                if (pos(cur) > 0 and
                    pos(cur) not_eq i) {
                    ans = (visited(cur) < ans) ? (visited(cur)) : (ans);
                    break;
                }

                for (const point& d : diff) {
                    point next = cur + d;
                    if (isSafe(next) and
                        not visited(next)) {
                        q.push(next);
                        visited(next) = visited(cur) + 1;
                    }
                }

            }

        }
    }

    void output(void) {
        cout << ans - 2;
    }

};

int main(void) {
    ios_base::sync_with_stdio(false);

    Island island;
    island.solve();

    return 0;
}