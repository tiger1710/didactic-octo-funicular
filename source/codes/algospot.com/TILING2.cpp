#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class Tiling2 {
private:
    int n, ans;
    vector<int> cache;

    int tiling(const int& width) {
        if (width <= 1) return 1;

        int& ret = cache[width];
        if (ret) return ret;

        return ret = (tiling(width - 1) + tiling(width - 2)) % 1000000007;
    }
    void input(void) { cin >> n; cache = vector<int>(n + 1); }
    void calc(void) { ans = tiling(n); }
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
    Tiling2 t;
    while (C--)
        t.solve();


    return 0;
}