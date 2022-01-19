#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)
using point = pair<int, int>; //typedef

int M, N;
vector<vector<int> > box;
vector<point> start;
const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };

bool condition(const point& p) {
    return (0 <= p.first and p.first < N and 0 <= p.second and p.second < M) and
            box[p.first][p.second] == 0;
}

int bfs(void) {
    int cnt = -1;
    queue<point> q;
    for (const point& s : start) {
        q.push(s);
    }

    while (not q.empty()) {
        int qSize = q.size();
        REP (i, 0, qSize) {
            point curr = q.front(); q.pop();
            for (const point& d : diff) {
                point next = point(curr.first + d.first, curr.second + d.second);
                if (condition(next)) {
                    box[next.first][next.second] = 1;
                    q.push(next);
                }
            }
        }
        cnt++;
    }


    REP (row, 0, N) {
        REP (col, 0, M) {
            if (box[row][col] == 0) {
                return -1;
            }
        }
    }
    
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> M >> N;
    box = vector<vector<int> >(N, vector<int>(M));
    REP (row, 0, N) {
        REP (col, 0, M) {
            cin >> box[row][col];
            if (box[row][col] == 1) {
                start.push_back(point(row, col));
            }
        }
    }

    int ans = bfs();
    cout << ans << endl;


    return 0;
}
