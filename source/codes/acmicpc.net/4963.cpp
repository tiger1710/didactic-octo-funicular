#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a); i < (b); i++)

class P4963 {
private:
    int w, h;
    int cnt;
    vector<vector<int> > map;
    vector<vector<bool> > visited;
    const int dr[8] = { -1, 1, 0, 0, -1, 1, -1 ,1 };
    const int dc[8] = { 0, 0, -1, 1, 1, -1, -1, 1 };

    bool isSafe(const int& r, const int& c) {
        return 0 <= r and r < h and 0 <= c and c < w;
    }
    void dfs(const int& r, const int& c) {
        visited[r][c] = true;
        REP(i, 0, 8) {
            int nextR = r + dr[i];
            int nextC = c + dc[i];
            if (isSafe(nextR, nextC) and
                map[r][c] and
                not visited[nextR][nextC]) {
                dfs(nextR, nextC);
            }
        }
    }

    int input(void) {
        cnt = 0;
        cin >> w >> h;
        if (w == 0 and h == 0) return -1;
        map = vector<vector<int> >(h, vector<int>(w));
        visited = vector<vector<bool> >(h, vector<bool>(w, false));
        for (vector<int>& r : map)
            for (int& c : r)
                cin >> c;
        
        return 0;
    }

    void calc(void) {
        REP(r, 0, h)
            REP(c, 0, w)
                if (map[r][c] and
                    not visited[r][c]) {
                    dfs(r, c);
                    cnt++;
                }
    }
    void output(void) {
        cout << cnt << endl;
    }
public:
    void solve(void) {
        while (input() not_eq -1) {
            calc();
            output();
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    P4963 p;
    p.solve();


    return 0;
}
