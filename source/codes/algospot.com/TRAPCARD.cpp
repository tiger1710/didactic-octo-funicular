#include <iostream>
#include <algorithm>
#include <cassert>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

class BipartiteMatching {
private:
    friend class TrapCard;
    int n, m;
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
    BipartiteMatching(const vector<vector<int>>& adj,
                        const int& n, const int& m) : adj(adj), n(n), m(m) { }
    int bipartiteMatch(void) {
        aMatch = vector<int>(n, -1);
        bMatch = vector<int>(m, -1);
        int size = 0;
        for (int start = 0; start < n; start++) {
            visited = vector<bool>(n, false);
            if(dfs(start)) size++;
        }
        return size;
    }
};

class TrapCard {
private:
    const point diff[4] = { point(1, 0), point(-1, 0), point(0, -1), point(0, 1) };

    int n, m;
    vector<vector<char>> base;

    vector<vector<int>> adj;
    vector<int> aMatch, bMatch;
    vector<bool> aChosen, bChosen;

    bool inRange(const int& r, const int& c) {
        return 0 <= r and r < n and
                0 <= c and c < m;
    }
    void init(void) {
        vector<vector<int>> id(n, vector<int>(m, -1));

        int cnt[2] = { 0, 0 };

        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (base[r][c] == '.') {
                    if ((r + c) & 1) id[r][c] = cnt[0]++;
                    else id[r][c] = cnt[1]++;
                }

        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (((r + c) & 1) and base[r][c] == '.')
                    for (int i = 0; i < 4; i++) {
                        int nr = r + diff[i].first, nc = c + diff[i].second;
                        if (inRange(nr, nc) and base[nr][nc] == '.')
                            adj[nr][nc] = 1;
                    }

    }


    void input(void) {
        cin >> n >> m;
        base = vector<vector<char>>(n, vector<char>(m));

        cin.ignore();
        for (vector<char>& r : base) {
            for (char& c : r)
                cin >> c;
            cin.ignore();
        }
    }
    void calc(void) {
        init();
        BipartiteMatching bm(adj, n, m);
        int C = bm.bipartiteMatch();
        aMatch.swap(bm.aMatch);
        bMatch.swap(bm.bMatch);

        // 1. A의 모든 정점들을 선택하고, B에서 대응되지 않은 정점들을 선택한다. 
        aChosen = vector<bool>(n, true);
        bChosen = vector<bool>(m, false);
        for (int i = 0; i < m; i++)
            if (bMatch[i] == -1)
                bChosen[i] = true;

        //2. 두 정점이 연결되어 있을 경우, 그중 A의 정점을 지우고 B의 대응된 정점을
        //대신 선택한다. 더이상 변화가 일어나지 않을 때까지 반복한다.
        while (true) {
            bool changed = false;
            for (int i = 0; i < n; i++)
                for (int k = 0; k < m; k++)
                    if (aChosen[i] and bChosen[k] and adj[i][k]) {
                        assert(aMatch[i] not_eq -1);
                        aChosen[i] = false;
                        bChosen[aMatch[i]] = true;
                        changed = true;
                    }
            if (not changed) break;
        }
    }
    void output(void) {
        int cnt = 0;
        for (const vector<bool>::reference& i : aChosen)
            if (i) cnt++;
        for (const vector<bool>::reference& i : bChosen)
            if (i) cnt++;
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

    int C; cin >> C;
    TrapCard tc;
    while (C--)
        tc.solve();

    return 0;
}