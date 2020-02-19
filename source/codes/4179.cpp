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

class Fire {
private:
    const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };

    int R, C;
    vector<vector<char>> maze;
    vector<vector<int>> visit;
    vector<point> fire;
    point J;
    int ans = -1;

    char& pos(const point& p) {
        return maze[p.first][p.second];
    }
    int& visited(const point& p) {
        return visit[p.first][p.second];
    }
    bool escape(const point& p) {
        return pos(p) == 'J' and (p.first == 0 or p.first == R - 1 or p.second == 0 or p.second == C - 1);
    }
    bool isSafe(const point& p) {
        return (unsigned)(p.first) < R and (unsigned)(p.second) < C;
    }
    void firemove(queue<point>& q, const point& cur) {
        for (const point& d : diff) {
            const point next(cur + d);
            if (isSafe(next) and
                not visited(next) and
                pos(next) not_eq '#') {
                q.push(next);
                pos(next) = 'F';
                visited(next) = visited(cur) + 1;
            }
        }
    }
    void jihunmove(queue<point>& q, const point& cur) {
        for (const point& d : diff) {
            const point next(cur + d);
            if (isSafe(next) and
                not visited(next) and
                pos(next) == '.') {
                q.push(next);
                pos(next) = 'J';
                visited(next) = visited(cur) + 1;
            }
        }
    }

    void input(void) {
        cin >> R >> C; cin.ignore();
        maze = vector<vector<char>>(R, vector<char>(C));
        visit = vector<vector<int>>(R, vector<int>(C));
        for (auto& row : maze) {
            for (auto& col : row) {
                cin >> col;
                switch (col) {
                    case 'J': J = point(&row - &maze[0], &col - &row[0]);
                        break;
                    case 'F': fire.push_back(point(&row - &maze[0], &col - &row[0]));
                        break;
                    default:
                        break;
                }
            }
        }
    }

    void calc(void) {
        queue<point> q;
        for (const point& p : fire) {
            q.push(p); visited(p) = 1;
        }
        q.push(J); visited(J) = 1;

        while (not q.empty()) {
            point cur = q.front(); q.pop();
            if (escape(cur)) {
                ans = visited(cur);
                break;
            }

            switch (pos(cur)) {
            case 'F': firemove(q, cur);
                break;
            case 'J': jihunmove(q, cur);
                break;
            default:
                break;
            }
        }
    }

    void output(void) {
        if (ans not_eq -1) cout << ans;
        else cout << "IMPOSSIBLE";
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

    Fire jihun_want_escape;
    jihun_want_escape.solve();

    return 0;
}