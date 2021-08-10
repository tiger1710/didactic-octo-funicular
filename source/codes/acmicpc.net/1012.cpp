#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a); i < (b); i++)

int farm[51][51] = { 0, };
bool visited[51][51] = { false, };
int M, N, K;

bool isSafe(const int& r, const int& c) {
    return 0 <= r and r < N and 0 <= c and c < M;
}

void dfs(const int& r, const int& c) {
    static const int dr[4] = { -1, 1, 0, 0 };
    static const int dc[4] = { 0, 0, -1, 1 };

    visited[r][c] = true;
    REP(i, 0, 4) {
        int nextR = r + dr[i];
        int nextC = c + dc[i];
        if (isSafe(nextR, nextC) and
            farm[nextR][nextC] and
            not visited[nextR][nextC]) {
            dfs(nextR, nextC);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int testcase; cin >> testcase;

    while (testcase--) {
        int cnt = 0;
        cin >> M >> N >> K;
        REP(i, 0, K) {
            int X, Y; cin >> X >> Y;
            farm[Y][X] = 1;
        }

        REP(r, 0, N) {
            REP(c, 0, M) {
                if (not visited[r][c] and
                    farm[r][c]) {
                    dfs(r, c);
                    cnt++;
                }
            }
        }
        memset(farm, 0, sizeof(farm));
        memset(visited, false, sizeof(visited));
        cout << cnt << endl;
    }

    return 0;
}
