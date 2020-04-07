#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class TriPathCnt {
private:
    int n, ans;
    enum Type { CALC, CNT };
    vector<vector<int>> triangle, cache[2];

    int path(const int& r, const int& c) {
        if (r == n - 1) return triangle[r][c];
        int& ret = cache[CALC][r][c];
        if (ret not_eq -1) return ret;
        return ret = max(path(r + 1, c), path(r + 1, c + 1)) + triangle[r][c];
    }
    int count(const int& r, const int& c) {
        if (r == n - 1) return 1;
        int& ret = cache[CNT][r][c];
        if (ret not_eq -1) return ret;
        ret = 0;
        if (path(r + 1, c) >= path(r + 1, c + 1)) ret += count(r + 1, c);
        if (path(r + 1, c) <= path(r + 1, c + 1)) ret += count(r + 1, c + 1);
        return ret;
    }

    void input(void) {
        cin >> n;
        triangle = cache[CALC] = cache[CNT] = vector<vector<int>>(n);
        for (int m = 0; m < n; m++) {
            triangle[m] = vector<int>(m + 1);
            cache[CALC][m] = cache[CNT][m] = vector<int>(m + 1, -1);
            for (int& i : triangle[m])
                cin >> i;
        }
    }
    void calc(void) { ans = count(0, 0); }
    void output(void) { cout << ans << endl; }
public:
    void solve(void) {
        input();
        calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int C; cin >> C;
    TriPathCnt tpc;
    while (C--) tpc.solve();
    

    return 0;
}