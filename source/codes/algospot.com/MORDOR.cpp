#include <iostream>
#include <vector>
#include <limits>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

class SegmentTree {
private:
    vector<point> minmax;//first : min, second : max
    int n;
    point init(const vector<int>& signs, const int& left, const int& right, const int& node) {
        if (left + 1 == right) return minmax[node] = point(signs[left], signs[left]);
        
        const int mid = (left + right) >> 1;
        
        const point leftMinMax = init(signs, left, mid, (node << 1) + 1);
        const point rightMinMax = init(signs, mid, right, (node << 1) + 2);
        
        return minmax[node] = point(min(leftMinMax.first, rightMinMax.first),
                    max(leftMinMax.second, rightMinMax.second));
    }
    point query(const int& left, const int& right, const int& node, const int& nodeLeft, const int& nodeRight) {
        if (right <= nodeLeft or nodeRight <= left)
            return point(numeric_limits<int>::max(), numeric_limits<int>::min());
        if (left <= nodeLeft and nodeRight <= right) return minmax[node];
        
        const int mid = (nodeLeft + nodeRight) >> 1;
        
        const point leftMinMax = query(left, right, (node << 1) + 1, nodeLeft, mid);
        const point rightMinMax = query(left, right, (node << 1) + 2, mid, nodeRight);
        
        
        return point(min(leftMinMax.first, rightMinMax.first), max(leftMinMax.second, rightMinMax.second));
    }
public:
    SegmentTree(const vector<int>& signs) {
        n = signs.size();
        minmax = vector<point>(n << 2);
        init(signs, 0, n, 0);
    }
    
    point query(const int& left, const int& right) { return query(left, right, 0, 0, n); }
};

class Mordor {
private:
    int N, Q;
    vector<int> signs;
    vector<int> ans;
    void input(void) {
        cin >> N >> Q;
        signs = vector<int>(N);
        for (int& i : signs) cin >> i;
    }
    void calc(void) {
        SegmentTree segTree(signs);
        while (Q--) {
            int l, r; cin >> l >> r; r++;
            point res = segTree.query(l, r);
            ans.push_back(res.second - res.first);
        }
    }
    void output(void) {
        for (const int& diff : ans) cout << diff << endl;
        ans.clear();
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
    Mordor mordor;
    while (C--)
        mordor.solve();


    return 0;
}