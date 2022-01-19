#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

using emoji = pair<int, int>;
bool visited[2000][1001];
int S;

void input(void) {
    cin >> S;
}

int bfs(void) {
    queue<emoji> q;
    q.push(emoji(1, 0));
    visited[1][0] = true;

    int minimum = 0;
    while (not q.empty()) {
        size_t size = q.size();
        REP (i, 0, size) {
            const emoji curr = q.front(); q.pop();

            if (curr.first == S) {
                return minimum;
            }

            emoji diff[3] = {
                emoji(curr.first, curr.first),
                emoji(curr.first + curr.second, curr.second),
                emoji(curr.first - 1, curr.second)
            };

            for (const emoji& next : diff) {
                if (0 < next.first and next.first < 2000 and
                not visited[next.first][next.second]) {
                    q.push(next);
                    visited[next.first][next.second] = true;
                }
            }
        }
        minimum++;
    }
    return minimum;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    int ans = bfs();
    cout << ans << endl;

    return 0;
}
