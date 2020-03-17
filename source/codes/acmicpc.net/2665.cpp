#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//https://justicehui.github.io/medium-algorithm/2018/08/30/01BFS/
//https://justicehui.github.io/koi/2019/03/09/BOJ2665/ Âü°í

typedef pair<int, int> point;
point operator+(const point& a, const point& b) { return point(a.first + b.first, a.second + b.second); }

class Makemaze {
private:
    enum { black, white };
    const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };
    point start, end;
    int n;
    vector<vector<char>> room;
    vector<vector<int>> dist;

    bool safe(const point& p) { return (unsigned)(p.first) < n and (unsigned)(p.second) < n; }
    int& distance(const point& p) { return dist[p.first][p.second]; }
    int cost(const point& p) { return room[p.first][p.second] ? 0 : 1; }

    void input(void) {
        (cin >> n).ignore();
        room = vector<vector<char>>(n, vector<char>(n));
        dist = vector<vector<int>>(n, vector<int>(n, 987654321));
        for (auto& r : room) {
            for (char& c : r)
                c = cin.get() - '0';
            cin.ignore();
        }
        start = point(0, 0); end = point(n - 1, n - 1);
    }
    void calc(void) {
        deque<point> q; q.push_back(start); distance(start) = 0;
        while (not q.empty()) {
            point cur = q.front(); q.pop_front();

            for (const point& d : diff) {
                point next(cur + d);
                if (safe(next) and 
                    distance(next) > distance(cur) + cost(next)) {
                    distance(next) = distance(cur) + cost(next);
                    switch (cost(next)) {
                    case 0:
                        q.push_front(next);
                        break;
                    case 1:
                        q.push_back(next);
                        break;
                    default:break;
                    }
                }
            }
        }
    }
    void output(void) {
        cout << distance(end);
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

    Makemaze maze;
    maze.solve();

    return 0;
}