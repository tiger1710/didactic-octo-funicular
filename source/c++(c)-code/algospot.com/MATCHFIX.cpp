#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
//https://blog.naver.com/kks227/220804885235


class Edge {
private:
    int target, capacity, flow;
    Edge* reverse;
public:
    int getTarget(void) const { return target; }
    int residualCapacity(void) const { return capacity - flow; }
    void push(const int& amt) {
        flow += amt;
        reverse->flow -= amt;
    }
    void init(const int& target, const int& capacity, Edge* p) {
        this->target = target;
        this->capacity = capacity;
        this->flow = 0;
        this->reverse = p;
    }
};

class MatchFix {
private:
    int N, M, ans, canWin;
    vector<int> wins;
    vector<pair<int, int>> match;
    vector<vector<Edge*>> adj;

    void addEdge(const int& u, const int& v, const int& capacity) {
        Edge* uv = new Edge;
        Edge* vu = new Edge;
        uv->init(v, capacity, vu);
        vu->init(u, 0, uv);
        adj[u].push_back(uv);
        adj[v].push_back(vu);
    }
    int networkFlow(void) {
        int totalFlow = 0;
        int V = 2 + M + N;
        while (true) {
            vector<int> parent(V, -1);
            vector<Edge*> path(V, nullptr);
            queue<int> q;
            parent[0] = 0;
            q.push(0);
            while (not q.empty() and parent[1] == -1) {
                int here = q.front(); q.pop();
                for (Edge*& p : adj[here]) {
                    const int there = p->getTarget();
                    if (p->residualCapacity() > 0 and parent[there] == -1) {
                        q.push(there);
                        parent[there] = here;
                        path[there] = p;
                    }
                }
            }
            if (parent[1] == -1) break;

            int amount = 987654321;
            for (int p = 1; p not_eq 0; p = parent[p])
                amount = min(path[p]->residualCapacity(), amount);
            for (int p = 1; p not_eq 0; p = parent[p])
                path[p]->push(amount);
            
            totalFlow += amount;
        }
        return totalFlow;
    }
    bool canWinWith(const int& totalWins) {
        if (*max_element(wins.begin() + 1, wins.end()) >= totalWins)
            return false;
        //cout << "current win : " << totalWins << endl;
        return networkFlow() == M;
    }
    void makeEdge(const int& totalWins) {
        adj = vector<vector<Edge*>>(2 + N + M);
        for (int i = 0; i < M; i++) {
            //source -> match
            addEdge(0, 2 + i, 1);

            //match -> player
            addEdge(2 + i, 2 + M + match[i].first, 1);
            addEdge(2 + i, 2 + M + match[i].second, 1);
        }

        //player -> sink
        addEdge(2 + M, 1, totalWins - wins[0]);
        int w = totalWins - 1;
        for (int i = 1; i < N; i++)
            if (w - wins[i] > 0)
                addEdge(2 + M + i, 1, w - wins[i]);
    }
    void deleteEdge(void) {
        for (vector<Edge*>& r : adj)
            for (Edge*& c : r)
                delete c;

    }

    void input(void) {
        cin >> N >> M;
        canWin = 0;
        wins = vector<int>(N);
        match = vector<pair<int, int>>(M);
        for (int& i : wins) cin >> i;
        for (pair<int, int>& m : match) {
            cin >> m.first >> m.second;
            if (m.first == 0 or m.second == 0) canWin++;
        }
        makeEdge(wins[0]);
    }
    void calc(void) {
        int w = wins[0];
        for (int i = 0; i <= canWin; i++) {
            if (canWinWith(w)) {
                ans = w;
                return;
            }
            w++;
            deleteEdge();
            makeEdge(w);
        }
        deleteEdge();

        ans = -1;
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
    
    int C; cin >> C;
    MatchFix mf;
    while (C--)
        mf.solve();

    return 0;
}