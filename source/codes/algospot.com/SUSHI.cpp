#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Sushi {
private:
    int n, m; //종류, 예산
    int ans;
    vector<int> price, pref, cache;

    int sushi(void) {
        int ret = 0;
        cache[0] = 0;
        for (int buget = 1; buget <= m; buget++) {
            int cand = 0;
            for (int dish = 0; dish < n; dish++)
                if (buget >= price[dish])
                    cand = max(cand, cache[(buget - price[dish]) % 201] + pref[dish]);
            cache[buget % 201] = cand;
            ret = max(ret, cand);
        }
        return ret;
    }
    void input(void) {
        cin >> n >> m;
        m /= 100;
        price = pref = vector<int>(n);
        cache = vector<int>(201);
        for (int i = 0; i < n; i++) {
            cin >> price[i] >> pref[i];
            price[i] /= 100;
        }
    }
    void calc(void) {
        ans = sushi();
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

    int c;
    cin >> c;
    Sushi s;
    while (c--)
        s.solve();

    return 0;
}