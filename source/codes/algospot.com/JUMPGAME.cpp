#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class JumpGame {
private:
    int n;
    vector<vector<int>> map, cache;
    bool ans;

    bool jump(const int& r, const int& c) {
        if (n <= r or n <= c) return false;
        if (r == n - 1 and c == n - 1) return true;

        int& ret = cache[r][c];
        if (ret not_eq -1) return ret;

        const int& jumpSize = map[r][c];
        
        return ret = jump(r + jumpSize, c) or jump(r, c + jumpSize);
    }

    void input(void) {
        cin >> n;
        map = cache = vector<vector<int>>(n, vector<int>(n, -1));
        for (auto& r : map)
            for (int& c : r)
                cin >> c;
    }
    void calc(void) {
        ans = jump(0, 0);
    }
    void output(void) {
        cout << (ans ? "YES" : "NO") << endl;
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
    JumpGame jg;
    for (int testCase = 0; testCase < C; testCase++)
        jg.solve();


    return 0;
}