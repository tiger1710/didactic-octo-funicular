#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class TrianglePath {
private:
    int n, ans;
    vector<vector<int>> triangle, cache;

    int path(const int& r, const int& c) {
        if (r == n - 1) return triangle[r][c];
        int& ret = cache[r][c];
        if (ret) return ret;

        return ret = max(path(r + 1, c), path(r + 1, c + 1)) + triangle[r][c];
    }
    void input(void) {
        cin >> n;
        triangle = cache = vector<vector<int>>(n);
        for (int r = 0; r < n; r++) {
            triangle[r] = cache[r] = vector<int>(r + 1);
            for (int& c : triangle[r])
                cin >> c;
        }
    }
    void calc(void) {
        ans = path(0, 0);
    }
    void output(void) {
        cout << ans << endl;
    }
public:
    void sovle(void) {
        input();
        calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C; cin >> C;
    TrianglePath tp;
    for (int testCase = 0; testCase < C; testCase++) {
        tp.sovle();
    }

    return 0;
}