#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

class Morse {
private:
    int n, m, k;
    const int M = 1000000000 + 100;
    string ans;

    int bino[201][201] = { 0, };
    void calcBino(void) {
        for (int i = 0; i <= 200; i++) {
            bino[i][0] = bino[i][i] = 1;
            for (int k = 1; k < i; k++)
                bino[i][k] = min(M, bino[i - 1][k - 1] + bino[i - 1][k]);
        }
    }
    string kth(const int& n, const int& m, const int& skip) {
        if (n == 0) return string(m, 'o');
        if (skip < bino[n + m][n]) return "-" + kth(n - 1, m, skip);
        return "o" + kth(n, m - 1, skip - bino[n + m][n]);
    }

    void input(void) {
        cin >> n >> m >> k;
    }
    void calc(void) {
        ans = kth(n, m, k);
    }
    void output(void) {
        cout << ans << endl;
    }
public:
    Morse(void) { calcBino(); }
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
    Morse m;
    while (C--)
        m.solve();


    return 0;
}