#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class NumberGame {
private:
    const int EMPTY = -987654321;
    int n, ans;
    vector<int> board;
    vector<vector<int>> cache;

    int play(const int& left, const int& right) {
        if (left > right) return 0;
        int& ret = cache[left][right];
        if (ret not_eq EMPTY) return ret;

        ret = max(board[left] - play(left + 1, right),
                    board[right] - play(left, right - 1));
        
        if (2 <= right - left + 1) {
            ret = max(ret, -play(left + 2, right));
            ret = max(ret, -play(left, right - 2));
        }

        return ret;
    }
    void input(void) {
        cin >> n;
        board = vector<int>(n);
        cache = vector<vector<int>>(n, vector<int>(n, EMPTY));
        for (int& i : board) cin >> i;
    }
    void calc(void) {
        ans = play(0, n - 1);
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
    
    NumberGame ng;
    int C; cin >> C;
    while (C--)
        ng.solve();

    return 0;
}