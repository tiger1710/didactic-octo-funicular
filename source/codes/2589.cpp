#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

point operator+(const point& p1, const point& p2) {
    return point(p1.first + p2.first, p1.second + p2.second);
}

class Treasure {
private:
    enum { land = 'L', water = 'W'};
    const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };
    int row, col;
    int ans = 0;
    vector<vector<char>> map;
    vector<vector<int>> visit;

    char& pos(const point& p) {
        return map[p.first][p.second];
    }
    int& visited(const point& p) {
        return visit[p.first][p.second];
    }
    bool isSafe(const point& p) {
        return (unsigned)(p.first) < row and  (unsigned)(p.second) < col;
    }

    void input(void) {
        cin >> row >> col; cin.ignore();
        map = vector<vector<char>>(row, vector<char>(col));
        for (auto& r : map) {
            for (auto& c : r) {
                c = cin.get();
            }
            cin.ignore();
        }
    }

    void bfs(const point& p) {
        visit = vector<vector<int>>(row, vector<int>(col));
        queue<point> q; q.emplace(p); visited(p) = 1;
        int res = 0;

        while (not q.empty()) {
            const point cur = q.front(); q.pop();
            res = res < visited(cur) ? visited(cur) : res;

            for (auto& d : diff) {
                const point next(cur + d);
                if (isSafe(next) and
                    pos(next) == land and
                    not visited(next)) {
                    q.emplace(next);
                    visited(next) = visited(cur) + 1;
                }
            }
        }

        ans = ans < res ? res : ans;
    }

    void calc(void) {
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (pos(point(r, c)) == land) {
                    bfs(point(r, c));
                }
            }
        }
    }

    void output(void) {
        cout << ans - 1;
    }
public:
    void solve(void) {
        input();
        calc();
        output();
    }

};

int main(void) {
    ios_base::sync_with_stdio(false);

    Treasure t;
    t.solve();

    return 0;
}