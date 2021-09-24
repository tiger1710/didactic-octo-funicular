#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

using point = pair<int, int>;

int R, C;
string maze[1000];
bool visited[1000][1000];
point J;
vector<point> fire;

void bfs(void) {
    queue<point> jq, fq;
    jq.push(J); visited[J.first][J.second] = true;

    for (const point& f : fire) {
        fq.push(f); visited[f.first][f.second];
    }

    while (not jq.empty()) {

    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;

    REP (r, 0, R) {
        cin >> maze[r];
    }

    REP (r, 0, R) {
        REP (c, 0, C) {
            if (maze[r][c] == 'J') {
                J = point(r, c);
            } else if (maze[r][c] == 'F') {
                fire.push_back(point(r, c));
            }
        }
    }






    return 0;
}