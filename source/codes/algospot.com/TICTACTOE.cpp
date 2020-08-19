#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

class TicTacToe {
private:
    vector<string> board;
    vector<int> cache;

    bool isFinished(const char& turn) {

    }
    int bijection(void) {
        int ret = 0;
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++) {
                ret *=3 ;
                if (board[r][c] == 'o') ret++;
                else if (board[r][c] == 'x') ret += 2;
            }
        return ret;
    }
    int canWin(const char& turn) {
        if (isFinished('o' + 'x' - turn)) return -1;
        int& ret = cache[bijection()];
        if (ret not_eq -2) return ret;

        int minValue = 2;
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                if (board[r][c] == '.') {
                    board[r][c] = turn;
                    minValue = min(minValue, canWin('o' + 'x' - turn));
                    board[r][c] = '.';
                }
        
        if (minValue == 2 or minValue == 0) return ret = 0;
        return ret = -minValue;
    }

    void input(void) {
        cache = vector<int>(19683, -2);//3^9
    }
public:
    void solve(void) {

    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C; cin >> C;
    TicTacToe ttt;
    while (C--)
        ttt.solve();


    return 0;
}