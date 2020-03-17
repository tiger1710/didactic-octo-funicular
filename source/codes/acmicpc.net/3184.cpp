#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;
typedef pair<int, int> sheep_and_wolf;

point operator+(const point& p1, const point& p2) {
    return point(p1.first + p2.first, p1.second + p2.second);
}

class Backyard {
private:
    const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };
    enum { field = '.', fence = '#', sheep = 'o', wolf = 'v' };

    int R, C;
    vector<vector<char>> backyard;
    vector<vector<bool>> visit;
    int o = 0;//sheep
    int v = 0;//wolf

    bool isSafe(const point& p) {
        return (unsigned)(p.first) < R and (unsigned)(p.second) < C;
    }
    vector<bool>::reference visited(const point& p) {
        return visit[p.first][p.second];
    }
    char pos(const point& p) {
        return backyard[p.first][p.second];
    }
    bool condition(const point& p) {
        return isSafe(p) and (not visited(p)) and (pos(p) not_eq fence);
    }
    void cnt(const sheep_and_wolf& n) {
        n.first > n.second ? (o += n.first) : (v += n.second);
    }

    void dfs(const point& cur, sheep_and_wolf& cnt) {
        visited(cur) = true;
        switch (pos(cur)) {
        case sheep : cnt.first++;
            break;
        case wolf : cnt.second++;
            break;
        default:
            break;
        }

        for (const point& d : diff) {
            const point next(cur + d);
            if (condition(next)) {
                dfs(next, cnt);
            }
        }
    }


    void input(void) {
        (cin >> R >> C).ignore();
        backyard = vector<vector<char>>(R, vector<char>(C));
        visit = vector<vector<bool>>(R, vector<bool>(C));

        for (auto& row : backyard) {
            for (auto& col : row)
                cin >> col;

            cin.ignore();
        }
    }

    void calc(void) {
        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                if (condition(point(row, col))) {
                    sheep_and_wolf n(0, 0);
                    dfs(point(row, col), n);
                    cnt(n);
                }
            }
        }
    }

    void output(void) {
        cout << o << ' ' << v;
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

    Backyard yard;
    yard.solve();

    return 0;
}