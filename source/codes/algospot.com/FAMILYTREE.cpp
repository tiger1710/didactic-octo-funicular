#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
class SegmentTree {
private:
    vector<int> tree;
    int n;
    int init(const vector<int>& arr, const int& left, const int& right, const int& node) {
        if (left + 1 == right) return tree[node] = arr[left];
        const int mid = (left + right) >> 1;
        
        const int leftMin = init(arr, left, mid, (node << 1) + 1);
        const int rightMin = init(arr, mid, right, (node << 1) + 2);
        
        return tree[node] = min(leftMin, rightMin);
    }
    int query(const int& left, const int& right, const int& node, const int& nodeLeft, const int& nodeRight) const {
        if (right <= nodeLeft or nodeRight <= left)
            return numeric_limits<int>::max();
        if (left <= nodeLeft and nodeRight <= right) return tree[node];
        
        const int mid = (nodeLeft + nodeRight) >> 1;
        
        return min(query(left, right, (node << 1) + 1, nodeLeft, mid),
                    query(left, right, (node << 1) + 2, mid, nodeRight));
    }
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size() + 1;
        tree = vector<int>(n << 2);
        init(arr, 0, n, 0);
    }
    
    int query(const int& left, const int& right) const {
        return query(left, right, 0, 0, n);
    }
};

class FamilyTree {
private:
    int N, Q;
    vector<vector<int>> children;
    vector<int> num2serial, serial2num, locInTrip, depth, trip, ans;
    
    int nextSerial;
    
    //search under node "cur" that depth[cur] = depth
    void traverse(const int& cur, const int& depth) {
        const int serial = nextSerial++;
        num2serial[cur] = serial;
        serial2num[serial] = cur;
        
        //calc depth
        this->depth[cur] = depth;
        locInTrip[cur] = trip.size();
        trip.push_back(num2serial[cur]);
        
        for (const int& child : children[cur]) {
            traverse(child, depth + 1);
            trip.push_back(num2serial[cur]);
        }
    }
    int distance(const SegmentTree& tree, const int& u, const int& v) {
        int lu = locInTrip[u], lv = locInTrip[v];
        if (lu > lv) swap(lu, lv);
        int lca = serial2num[tree.query(lu, lv + 1)];//[ ) 구간..
        return depth[u] + depth[v] - (depth[lca] << 1);
    }
    
    void input(void) {
        cin >> N >> Q;
        children = vector<vector<int>>(N);
        locInTrip = num2serial = serial2num = depth = vector<int>(N);
        nextSerial = 0;
        
        for (int i = 1; i < N; i++) {
            int parent; cin >> parent;
            children[parent].push_back(i);
        }
    }
    void calc(void) {
        traverse(0, 0);
        SegmentTree st(trip);
        while (Q--) {
            int u, v; cin >> u >> v;
            ans.push_back(distance(st, u, v));
        }
    }
    void output(void) {
        for (const int& d : ans)
            cout << d << endl;
        ans.clear();
        trip.clear();
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
    FamilyTree ft;
    while (C--)
        ft.solve();
        
    
    return 0;
}