#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

class BipartiteUnionFind {
private:
    friend class EditorWars;
    vector<int> parent, rank, enemy, size;
    int n;

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v) {
        if (u == -1 or v == -1) return max(u, v);
        u = find(u); v = find(v);
        if (u == v) return u;
        
        if (rank[u] > rank[v]) swap(u, v);
        if (rank[u] == rank[v]) rank[v]++;
        
        parent[u] = v;
        size[v] += size[u];
        
        return v;
    }
public:
    BipartiteUnionFind(const int& n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
        this->n = n;
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    bool dis(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        
        int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
        enemy[a] = b; enemy[b] = a;
        
        return true;
    }
    bool ack(int u, int v) {
        u = find(u); v = find(v);
        if (enemy[u] == v) return false;
        
        int a = merge(u, v), b = merge(enemy[u], enemy[v]);
        enemy[a] = b;
        if (b not_eq -1) enemy[b] = a;
        
        return true;
    }
    int maxParty(void) {
        int ret = 0;
        for (int node = 0; node < n; node++) {
            if (parent[node] == node) {
                int enemy = this->enemy[node];
                if (enemy > node) continue;
                int mySize = size[node];
                int enemySize = (enemy == -1 ? 0 : size[enemy]);
                ret += max(mySize, enemySize);
            }
        }
        return ret;
    }
};

class EditorWars {
private:
    int N, M, q;
    string ans;
    
    
    
    void input(void) {
        cin >> N >> M;
    }
    void calc(void) {
        BipartiteUnionFind buf(N);
        string str; int a, b; bool Q = true;
        for (int q = 0; q < M; q++) {
            cin >> str >> a >> b;
            if (str == "ACK") Q = buf.ack(a, b);
            else Q = buf.dis(a, b);
            
            if (not Q) {
                ans = "CONTRADICTION AT ";
                this->q = q + 1;
                
                for (int i = q + 1; i < M; i++)
                    cin >> str >> a >> b;
                return;
            }
        }
        
        ans = "MAX PARTY SIZE IS ";
        this->q = buf.maxParty();
    }
    void output(void) {
        cout << ans << q << endl;
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
    EditorWars ew;
    while (C--)
        ew.solve();
    
    
    return 0;
}
