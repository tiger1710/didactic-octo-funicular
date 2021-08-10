#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a); i < (b); i++)

using point = pair<int, int>;
point operator+(const point& a, const point& b) {
    return point(a.first + b.first, a.second + b.second);
}
class P2667 {
private:
    int N, cnt;
    vector<int> cntv;
    vector<string> map;
    vector<vector<bool> > visited;
    const point dp[4] = { {-1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

    bool isSafe(const point& p) {
        return 0 <= p.first and p.first < N and 0 <= p.second and p.second < N;
    }
    int dfs(const point& curr) {
        int room = 1;
        visited[curr.first][curr.second] = true;

        for (const point& d : dp) {
            point next = curr + d;
            if (isSafe(next) and
                not visited[next.first][next.second] and
                map[next.first][next.second] == '1') {
                room += dfs(next);
            }
        }

        return room;
    }

    void input(void) {
        cin >> N;
        visited = vector<vector<bool> >(N, vector<bool>(N));
        cnt = 0;

        REP(i, 0, N) {
            string str;
            cin >> str;
            map.push_back(str);
        }
    }
    void calc(void) {
        REP(r, 0, N)
            REP(c, 0, N) {
                if (not visited[r][c] and
                    map[r][c] == '1') {
                    cnt++;
                    cntv.push_back(dfs(point(r, c)));
                }
            }
    }
    void output(void) {
        sort(ALL(cntv));
        cout << cnt << endl;
        for (const int& i : cntv)
            cout << i << endl;
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

    P2667 p;
    p.solve();

    return 0;
}
