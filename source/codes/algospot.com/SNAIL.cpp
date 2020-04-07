#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class Snail {
private:
    int n, m;
    vector<vector<double>> cache;
    double ans;

    double climb(const int& day, const int& height) {
        if (day == m) return height < n ? 0 : 1;

        double& ret = cache[day][height];
        if (ret not_eq -1) return ret;
        return ret = 0.75 * climb(day + 1, height + 2) + 0.25 * climb(day + 1, height + 1);
    }

    void input(void) {
        cin >> n >> m;
        cache = vector<vector<double>>(m, vector<double>((m << 1) + 1, -1));
    }
    void calc(void) { ans = climb(0, 0); }
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

    (cout << fixed).precision(10);//추가해야 정답 ㅠㅠ...
    int C; cin >> C;
    Snail s;
    while (C--) s.solve();

    return 0;
}