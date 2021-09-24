#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)
using point = pair<int, int>;

int n;
vector<string> room;
vector<vector<int> > visited;

void input(void) {
    cin >> n;
    room.resize(n);
    visited.resize(n, vector<int>(n, 0));
    for (string& row : room) {
        cin >> row;
    }
}

bool condition(const point& p) {
    return 0 <= p.first and p.first < n and
        0 <= p.second and p.second < n and
        not visited[p.first][p.second];
}

int bfs01(void) {
    static const point diff[4] = {
        point(-1, 0), point(1, 0),
        point(0, -1), point(0, 1)
    };

    deque<point> q;
    q.push_front(point(0, 0));
    visited[0][0] = 1;

    while (not q.empty()) {
        const point curr(q.front()); q.pop_front();
        for (const point& d : diff) {
            const point next(curr.first + d.first, curr.second + d.second);
            if (condition(next)) {
                if (room[next.first][next.second] == '1') {
                    visited[next.first][next.second] = visited[curr.first][curr.second];
                    q.push_front(next);
                } else {
                    visited[next.first][next.second] = visited[curr.first][curr.second] + 1;
                    q.push_back(next);
                }
            }
        }
    }
    return visited[n - 1][n - 1] - 1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    cout << bfs01() << endl;

    return 0;
}
