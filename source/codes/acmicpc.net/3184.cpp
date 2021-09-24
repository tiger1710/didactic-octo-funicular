#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

using point = pair<int, int>;
using sheep_wolf = pair<int, int>;
point d[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };
vector<string> yard;
vector<vector<bool> > visited;
int R, C;

void input(void) {
    cin >> R >> C;
    yard.resize(R);
    visited = vector<vector<bool> >(R, vector<bool>(C, false));
    for (string& row : yard) {
        cin >> row;
    }
}

bool condition(const point& p) {
    return (0 <= p.first and p.first < R and 0 <= p.second and p.second < C) and
        not visited[p.first][p.second] and
        yard[p.first][p.second] not_eq '#';
}

void dfs(const point& curr, sheep_wolf& cnt) {
    visited[curr.first][curr.second] = true;

    if (yard[curr.first][curr.second] == 'o') {
        cnt.first++;
    } else if (yard[curr.first][curr.second] == 'v') {
        cnt.second++;
    }

    for (const point& diff : d) {
        const point next = point(curr.first + diff.first, curr.second + diff.second);
        if (condition(next)) {
            dfs(next, cnt);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sheep_wolf count = sheep_wolf(0, 0);
    input();

    REP (row, 0, R) {
        REP (col, 0, C) {
            if (condition(point(row, col))) {
                sheep_wolf region = sheep_wolf(0, 0);
                dfs(point(row, col), region);
                if (region.second < region.first) {
                    count.first += region.first;
                } else {
                    count.second += region.second;
                }
            }
        }
    }

    cout << count.first << ' ' << count.second << endl;


    return 0;
}
