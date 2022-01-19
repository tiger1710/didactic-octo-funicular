#include <iostream>
#include <algorithm>
#include <vector>
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
        for (int b = 0; b < m; b++)
            if (adj[a][b])
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
    const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };

    int n, m;
    vector<vector<char>> base;

    vector<vector<int>> id, adj;
    vector<int> aMatch, bMatch;
    vector<bool> aChosen, bChosen;
    vector<point> aPos, bPos;

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
                    if ((r + c) & 1) {
                        id[r][c] = cnt[1]++;//홀수
                        bPos.push_back(make_pair(r, c));
                    }
                    else {
                        id[r][c] = cnt[0]++;//짝수
                        aPos.push_back(make_pair(r, c));
                    }
                }

        adj = vector<vector<int>>(cnt[0], vector<int>(cnt[1], 0));
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                if (not ((r + c) & 1) and base[r][c] == '.')
                    for (int i = 0; i < 4; i++) {
                        int nr = r + diff[i].first, nc = c + diff[i].second;
                        if (inRange(nr, nc) and base[nr][nc] == '.')
                            adj[id[r][c]][id[nr][nc]] = 1;
                    }

        BipartiteMatching bm(adj, cnt[0], cnt[1]);
        int C = bm.bipartiteMatch();
        aMatch.swap(bm.aMatch);
        bMatch.swap(bm.bMatch);
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

        // 1. A의 모든 정점들을 선택하고, B에서 대응되지 않은 정점들을 선택한다. 
        aChosen = vector<bool>(aMatch.size(), true);
        bChosen = vector<bool>(bMatch.size(), false);
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
        for (int i = 0; i < aChosen.size(); i++)
            if (aChosen[i]) {
                cnt++;
                base[aPos[i].first][aPos[i].second] = '^';
            }
        for (int i = 0; i < bChosen.size(); i++)
            if (bChosen[i]) {
                cnt++;
                base[bPos[i].first][bPos[i].second] = '^';
            }
        aPos.clear(); bPos.clear();

        cout << cnt << endl;
        for (const vector<char>& r : base) {
            for (const char& c : r)
                cout << c;
            cout << endl;
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

    int C; cin >> C;
    TrapCard tc;
    while (C--)
        tc.solve();

    return 0;
}