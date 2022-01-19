#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class Poly {
private:
    const int MOD = 10000000;
    int n, ans;
    vector<vector<int>> cache;

    int poly(const int& n, const int& first) {
        if (n == first) return 1;

        int& ret = cache[n][first];
        if (ret not_eq -1) return ret;

        ret = 0;
        for (int second = 1; second <= n - first; second++) {
            int add = second + first - 1;
            add *= poly(n - first, second);
            add %= MOD;
            ret += add;
            ret %= MOD;
        }
        
        return ret;
    }

    void input(void) {
        cin >> n;
        cache = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    }
    void calc(void) {
        ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += poly(n , i);
            ans %= MOD;
        }
    }
    void output(void) {
        cout << ans << endl;
    }
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
    Poly poly;
    while (C--) {
        poly.solve();
    }


    return 0;
}