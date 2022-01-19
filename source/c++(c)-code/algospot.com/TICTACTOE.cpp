#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

class TicTacToe {
private:
    vector<string> board;
    vector<int> cache;
    char player;
    int oturn, xturn, ans;

    bool isFinished(const char& turn) {
        for (int r = 0; r < 3; r++)
            if (turn == board[r][0] and turn == board[r][1] and turn == board[r][2])
                return true;
        for (int c = 0; c < 3; c++)
            if (turn == board[0][c] and turn == board[1][c] and turn == board[2][c])
                return true;
        if (turn == board[0][0] and turn == board[1][1] and turn == board[2][2])
            return true;
        if (turn == board[0][2] and turn == board[1][1] and turn == board[2][0])
            return true;
        
        return false;
    }
    //board가 주어지면 int로 변환
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
    //win = 1, draw = 0, lose = -1;
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
        oturn = xturn = 0; board.clear();
        cache = vector<int>(19683, -2);//3^9
        for (int r = 0; r < 3; r++) {
            string row; cin >> row;
            board.push_back(row);
            for (const char& ch : row)
                switch (ch) {
                case 'x':
                    xturn++;
                    break;
                case 'o':
                    oturn++;
                    break;
                default:
                    break;
                }
        }
    }
    void calc(void) {
        player = oturn < xturn ? 'o' : 'x';
        ans = canWin(player);
    }
    void output(void) {
        switch (ans) {
        case 1:
            cout << (player == 'x' ? 'x' : 'o') << endl;
            break;
        case -1:
            cout << (player == 'x' ? 'o' : 'x') << endl;
            break;
        default:
            cout << "TIE" << endl;
            break;
        }
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
    TicTacToe ttt;
    while (C--)
        ttt.solve();


    return 0;
}