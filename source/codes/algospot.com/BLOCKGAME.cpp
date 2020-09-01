#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

class BlockGame {
private:
    int currentBoard;
    char canWin;
    vector<int> moves;
    vector<char> cache;
    int cell(const int& r, const int& c) { return 1 << (r * 5 + c); }
    void precalc(void) {
        //'L' shape 3 blocks
        for (int r = 0; r < 4; r++)
            for (int c = 0; c < 4; c++) {
                vector<int> cells;
                for (int dr = 0; dr < 2; dr++)
                    for (int dc = 0; dc < 2; dc++)
                        cells.push_back(cell(r + dr, c + dc));
                int squre = cells[0] + cells[1] + cells[2] + cells[3];
                for (int i = 0; i < 4; i++)
                    moves.push_back(squre - cells[i]);
            }
        
        //2 blocks
        for (int r = 0; r < 5; r++)
            for (int c = 0; c < 4; c++) {
                moves.push_back(cell(r, c) + cell(r, c + 1));
                moves.push_back(cell(c, r) + cell(c + 1, r));
            }
    }
    char play(const int& board) {
        char& ret = cache[board];
        if (ret not_eq -1) return ret;
        ret = 0;
        for (const int& next : moves)
            if ((board bitand next) == 0)
                if (not play(board bitor next)) {
                    ret = 1;
                    break;
                }
        return ret;
    }
    void input(void) {
        currentBoard = 0;
        cache = vector<char>(1 << 25, -1);
        cin.ignore();
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                char ch; cin >> ch;
                if (ch == '#')
                    currentBoard += cell(r, c);
            }
        }
    }
    void calc(void) {
        canWin = play(currentBoard);
    }
    void output(void) {
        cout << (canWin ? "WINNING" : "LOSING") << endl;
    }
public:
    BlockGame(void) {
        precalc();
    }
    void solve(void) {
        input();
        calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    int C; cin >> C;
    BlockGame bg;
    while (C--)
        bg.solve();


    return 0;
}