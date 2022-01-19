#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

class Ites {
private:
    unsigned seed;
    unsigned next(void) {
        unsigned ret = seed;
        seed = ((seed * 214013u) + 2531011u);
        return ret % 10000 + 1;
    }

    int K, N, ans;

    void input(void) { cin >> K >> N; ans = 0; seed = 1983u; }
    void calc(void) {
        queue<unsigned> range;
        unsigned sum = 0u;

        while (N--) {
            unsigned signal = next();
            sum += signal;
            range.push(signal);
            
            while (sum > K) {
                sum -= range.front();
                range.pop();
            }
            if (sum == K) ans++;
        }
    }
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
    Ites ites;
    while (C--) ites.solve();

    return 0;
}