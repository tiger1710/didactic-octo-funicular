#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class AsymTiling {
private:
    int n, ans;
    const int MOD = 1000000007;
    vector<int> cache;

    int tiling(const int& width) {
        if (width <= 1) return 1;
        int& ret = cache[width];
        if (ret) return ret;
        return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
    }
    int asymmetric(const int& width) {
        if (width & 1)
            return (tiling(width) - tiling(width >> 1) + MOD) % MOD;

        int ret = tiling(width);
        ret = (ret - tiling(width >> 1) + MOD) % MOD;
        ret = (ret - tiling((width >> 1) - 1) + MOD) % MOD;
        return ret;
    }

    void input(void) {
        cin >> n;
        cache = vector<int>(n + 1);
    }
    void calc(void) { ans = asymmetric(n); }
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
    AsymTiling at;
    while (C--) at.solve();

    return 0;
}