#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define endl '\n'
using namespace std;

class LIS {
private:
    int N, ans;
    vector<int> sequence, cache, nlogn;

    int lis(const int& index) {
        if (index == N) return 0;
        int& ret = cache[index];
        if (ret) return ret;

        ret = upper_bound(nlogn.begin(), nlogn.end(), sequence[index]) - nlogn.begin();
        if (ret < nlogn.size()) nlogn[ret] = sequence[index];
        else nlogn.push_back(sequence[index]);

        return max(ret, lis(index + 1));
    }

    void input(void) {
        cin >> N;
        sequence = cache = vector<int>(N);
        for (int& i : sequence) cin >> i;
        nlogn.clear();
    }
    void calc(void) {
        //nlogn Àû¿ë...?
        ans = lis(0);
    }
    void output(void) {
        cout << ans + 1 << endl;
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
    cin.tie(nullptr);

    int C; cin >> C;
    LIS lis;
    for (int testCase = 0; testCase < C; testCase++) {
        lis.solve();
    }
    
    return 0;
}