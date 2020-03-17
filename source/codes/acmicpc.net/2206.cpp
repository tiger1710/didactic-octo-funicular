#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

typedef pair<int, int> point;
typedef pair<point, short> position;

point operator+(const point& a, const point& b) { return point(a.first + b.first, a.second + b.second); }
const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };

class Move {
private:
    int N, M;
    vector<vector<char>> map;
    vector<vector<int>> visit[2];//[0]=not breaked, [1]=breaked

    int& visited(const position& p) {
        return visit[p.second][p.first.first][p.first.second];
    }
    bool safe(const point& p) {
        return (unsigned)(p.first) < N and (unsigned)(p.second) < M;
    }
    bool condition(const position& p) {
        return safe(p.first) and not visited(p) and map[p.first.first][p.first.second] == 0;
    }
    bool break_condition(const position& p) {
        return safe(p.first) and not visited(p);
    }

    void input(void) {
        (cin >> N >> M).ignore();
        map = vector<vector<char>>(N, vector<char>(M));
        visit[0] = visit[1] = vector<vector<int>>(N, vector<int>(M));
        for (auto& r : map) {
            for (char& c : r)
                c = cin.get() - '0';
            cin.ignore();
        }
    }
    void calc(void) {
        queue<position> q;
        q.push(position(point(0, 0), 0));
        visited(position(point(0, 0), 0)) = 1;

        while (not q.empty()) {
            position cur = q.front(); q.pop();

            for (const point& d : diff) {
                position next(cur.first + d, cur.second);

                if (condition(next)) {
                    q.push(next); visited(next) = visited(cur) + 1;
                }
                if (not cur.second and break_condition(next)) {
                    next.second = 1;
                    q.push(next);
                    visited(next) = visited(cur) + 1;
                }
            }
        }
    }
    void output(void) {
        const point fin(N - 1, M - 1);
        int nb = visited(position(fin, false));
        int b = visited(position(fin, true));

        if (nb == 0 and b == 0) cout << -1;
        else if (nb > 0 and b > 0) cout << min(nb, b);
        else cout << max(nb, b);
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

    Move m;
    m.solve();

    return 0;
}