#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<vector<int>, int> point;

class hashing {
public:
    size_t operator()(const point& p) const {
        return hash<string>()(string(p.first.begin(), p.first.end())) ^ hash<int>()(p.second);
    }
};


class Swap {
private:
    vector<int> N;
    int K;
    unordered_map<point, bool, hashing> visit;
    vector<int> ans, dummy;
    int size;

    bool visited(const point& val) {
        return visit.find(val) not_eq visit.end();
    }
    void dfs(const point& cur) {
        visit[cur] = true;
        if (cur.second == K) {
            ans = (ans < cur.first) ? (cur.first) : (ans);
            return;
        }
        for(int i = 0; i < size; i++) {
            for (auto j = i + 1; j < size; j++) {
                point next(cur.first, cur.second + 1); swap(next.first[i], next.first[j]);
                if (not visited(next) and next.first.front() not_eq 0) {
                    dfs(next);
                }
            }
        }
    }

    void input(void) {
        char ch;
        while ((ch = cin.get()) not_eq ' ') {
            N.push_back(ch - '0');
            ans.push_back(0); dummy.push_back(0);
        }
        cin >> K;
        size = N.size();
    }
    void calc(void) {
        dfs(point(N, 0));
    }
    void output(void) {
        if (ans == dummy) {
            cout << -1; return;
        }
        for (const int& i : ans) cout << i;
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

    Swap s;
    s.solve();

    return 0;
}