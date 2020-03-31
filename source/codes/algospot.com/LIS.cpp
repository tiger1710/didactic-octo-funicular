#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define endl '\n'
using namespace std;

class LIS {
private:
    int N, ans;
    vector<int> sequence, cache;

    void length(const int& index) {
        vector<int>::iterator loc = upper_bound(cache.begin(), cache.end(), sequence[index]);
        if (loc + 1 < cache.end()) *loc = sequence[index]; //update
        else cache.insert(loc, sequence[index]); //insert
    }

    void input(void) {
        cin >> N;
        sequence = vector<int>(N); cache.clear();
        for (int& i : sequence) cin >> i;
        cache.push_back(numeric_limits<int>::max());
    }
    void calc(void) {
        for (int i = 0; i < N; i++) length(i);
        ans = cache.size() - 1;
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
    cin.tie(nullptr);

    int C; cin >> C;
    LIS lis;
    for (int testCase = 0; testCase < C; testCase++) {
        lis.solve();
    }
    
    return 0;
}