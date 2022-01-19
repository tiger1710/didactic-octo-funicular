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

class Iceberg {
private:
    const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };
    vector<vector<int>> map;
    vector<vector<bool>> visit;
    int N, M;
    int ans = 0;
    const int water = 0;

    bool isSafe(const point& p) {
        return (unsigned)(p.first) < N and (unsigned)(p.second) < M;
    }
    vector<bool>::reference visited(const point& p) {
        return visit[p.first][p.second];
    }
    int& pos(const point& p) {
        return map[p.first][p.second];
    }

    bool check(const point& next) {
        return isSafe(next) and 
               pos(next) not_eq water and 
               not visited(next);
    }

    void melt(vector<vector<int>>& nextyear, const point& p) {
        int cnt = 0;
        for (const point& d : diff) {
            const point next(p + d);
            if (isSafe(next) and
                pos(next) == water) {
                cnt++;
            }
        }
        int& val = nextyear[p.first][p.second];
        val -= cnt;
        val = val < 0 ? water : val;
    }

    void dfs(const point& cur) {
        visited(cur) = true;
        for (const point& d : diff) {
            const point& next(cur + d);
            if (check(next)) {
                dfs(next);
            }
        }
    }

    void aging(void) {
        vector<vector<int>> nextyear(map);

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (pos(point(r, c)) not_eq water) {
                    melt(nextyear, point(r, c));
                }
            }
        }

        map.swap(nextyear);
        visit = vector<vector<bool>>(N, vector<bool>(M));
    }

    void input(void) {
        cin >> N >> M;
        map = vector<vector<int>>(N, vector<int>(M));
        visit = vector<vector<bool>>(N, vector<bool>(M));
        for (auto& r : map)
            for (auto& c : r)
                cin >> c;
    }

    void calc(void) {
        while (true) {
            int cnt = 0;
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < M; c++) {
                    if (check(point(r, c))) {
                        dfs(point(r, c)); cnt++;
                    }
                }
            }

            if (cnt > 1) break;
            if (cnt == 0) {
                ans = 0; break;
            }
            aging(); ans++;
        }
    }

    void output(void) {
        cout << ans;
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

    Iceberg ib;
    ib.solve();

    return 0;
}