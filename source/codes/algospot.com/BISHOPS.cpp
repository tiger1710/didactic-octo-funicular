#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

class BipartiteMatching {
private:
    vector<vector<int>> adj;
    vector<int> aMatch, bMatch;
    vector<bool> visited;

    bool dfs(const int& a) {
        if (visited[a]) return false;
        visited[a] = true;
        for (const int& b : adj[a])
            if (bMatch[b] == -1 or dfs(bMatch[b])) {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        return false;
    }
public:
    BipartiteMatching(const vector<vector<int>>& adj) : adj(adj) { }
    int bipartiteMatch(void) {
        aMatch = vector<int>(adj.size(), -1);
        bMatch = vector<int>(adj.size(), -1);
        int size = 0;
        for (int start = 0; start < adj.size(); start++) {
            visited = vector<bool>(adj.size(), false);
            if(dfs(start)) size++;
        }
        return size;
    }
};

class Bishops {
private:
    //leftdonw, rightdown
    const point diff[2] = { point(1, -1), point(1, 1) };

    //board
    int N;
    vector<vector<char>> board;
    vector<vector<int>> id[2];

    //graph
    int n, m;
    vector<vector<int>> adj;


    int ans;

    bool visited(const int& dir, const int& r, const int& c) {
        return board[r][c] not_eq '.' or id[dir][r][c] not_eq -1;
    }
    bool isSafe(const int& r, const int& c) {
        return board[r][c] == '.' and
                (0 <= r and r < N) and
                (0 <= c and c < N);
    }

    void init(void) {
        //번호 붙이기
        int count[2] = { 0, 0 };
        for (int dir = 0; dir < 2; dir++)
            for (int r = 0; r < N; r++)
                for (int c = 0; c < N; c++)
                    if (not visited(dir, r, c)) {
                        int nr = r, nc = c;
                        while (isSafe(nr, nc)) {
                            id[dir][nr][nc] = count[dir];
                            nr += diff[dir].first;
                            nc += diff[dir].second;
                        }
                        count[dir]++;
                    }

        //이분 그래프
        n = count[0]; m = count[1];
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                if (board[r][c] == '.')
                    adj[id[0][r][c]][id[1][r][c]] = 1;
    }

    //solve
    void input(void) {
        (cin >> N).ignore();
        board = vector<vector<char>>(N, vector<char>(N));
        for (vector<char>& r : board) {
            for (char& c : r)
                cin >> c;
            cin.ignore();
        }
    }
    void calc(void) {
        BipartiteMatching bm(adj);
        ans = bm.bipartiteMatch();
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

    int T; cin >> T;
    Bishops b;
    while (T--)
        b.solve();

    return 0;
}