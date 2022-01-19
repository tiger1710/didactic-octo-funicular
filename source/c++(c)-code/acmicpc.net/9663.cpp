#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

class Prob {
private:
    int N, ans;
    vector<vector<char> > placed;
    const char qdr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    const char qdc[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    bool isSafe(const char& r, const char& c) {
        return 0 <= r and r < N and 0 <= c and c < N;
    }
    void place(const int& r, const int& c, const char& n) {
        REP(i, 0, 8) {
            int nextR = r, nextC = c;
            while (isSafe(nextR, nextC)) {
                if (not placed[nextR][nextC])
                    placed[nextR][nextC] = n;
                nextR += qdr[i];
                nextC += qdc[i];
            }
        }
    }
    void unplace(const int& r, const int& c, const char& n) {
        REP(i, 0, 8) {
            int nextR = r, nextC = c;
            while (isSafe(nextR, nextC)) {
                if (placed[nextR][nextC] == n)
                    placed[nextR][nextC] = 0;
                nextR += qdr[i];
                nextC += qdc[i];
            }
        }
    }
    int dfs(const int& r, const int& c, const int& queenPlaced) {
        if (queenPlaced == N) return 1;
        int total = 0;
        place(r, c, queenPlaced);
        REP(nextR, r + 1, N)
            REP(nextC, 0, N)
                if (not placed[nextR][nextC])
                    total += dfs(nextR, nextC, queenPlaced + 1);
        unplace(r, c, queenPlaced);

        return total;
    }

    void input(void) {
        ans = 0;
        cin >> N;
        placed = vector<vector<char> >(N, vector<char>(N, 0));
    }
    void calc(void) {
        REP(r, 0, N)
            REP(c, 0, N)
                ans += dfs(r, c, 1);
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

class Prob2 {
private:
    int N, play;
    vector<int> column;

    bool canPlace(const int& currentRow) {
        REP(beforeRow, 0, currentRow) {
            if (column[beforeRow] == column[currentRow] || //in same column
            (abs(beforeRow - currentRow) == abs(column[beforeRow] - column[currentRow])) // in same diagonal
            ) return false;
        }
        return true;
    }

    void dfs(const int& row) {
        if (row == N) {
            play++;
            return;
        }
        REP(col, 0, N) {
            column[row] = col;
            if (canPlace(row))
                dfs(row + 1);
        }
    }
    void input(void) {
        cin >> N;
        column.resize(N);
        play = 0;
    }
    void calc(void) {
        dfs(0);
    }
    void output(void) {
        cout << play << endl;
    }

public:
    void solve(void) {
        input();
        calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Prob2 p;
    p.solve();


    return 0;
}