#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

point operator+(const point& a, const point& b) {
    return point(a.first + b.first, a.second + b.second);
}

class BoardCover {
private:
    int H, W, ans;
    vector<vector<char>> board;
    const point coverType[4][3] = {
        { point(0, 0), point(1, 0), point(0, 1) },
        { point(0, 0), point(0, 1), point(1, 1) },
        { point(0, 0), point(1, 0), point(1, 1) },
        { point(0, 0), point(1, 0), point(1, -1)}
    };

    bool inRange(const point& p) {
        return (unsigned)(p.first) < H and (unsigned)(p.second) < W;
    }
    bool put(const point& p, const int& t) {
        bool ok = true;
        for (const point& d : coverType[t]) {
            point points(p + d);
            if (not inRange(points) or
                board[points.first][points.second] == '#') {
                    ok = false; break;
                }
        }

        if (ok)
            for (const point& d : coverType[t]) {
                point points(p + d);
                board[points.first][points.second] = '#';
            }

        return ok;
    }
    void take(const point& p, const int& t) {
        for (const point& d : coverType[t]) {
            point points(p + d);
            board[points.first][points.second] = '.';
        }
    }
    point find(void) {
        for (int r = 0; r < H; r++)
            for (int c = 0; c < W; c++)
                if (board[r][c] == '.') return point(r, c);

        return point(-1, -1);
    }
    int cover(void) {
        point upleft = find();
        if (upleft == point(-1, -1)) return 1;

        int ret = 0;
        for (int i = 0; i < 4; i++) {
            if (put(upleft, i)) {
                ret += cover();
                take(upleft, i);
            }
        }
        return ret;
    }

    void input(void) {
        (cin >> H >> W).ignore();
        board = vector<vector<char>>(H, vector<char>(W));
        for (auto& h : board) {
            for (auto& w : h) {
                w = cin.get();
            }
            cin.ignore();
        }
    }
    void calc(void) {
        ans = cover();
    }
    void output(void) {
        cout << ans << endl;
    }
public:
    void solve(void) {
        input();
        calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int C;
    BoardCover bc;
    (cin >> C).ignore();
    for (int testCase = 0; testCase < C; testCase++)
        bc.solve(); 

    return 0;
}