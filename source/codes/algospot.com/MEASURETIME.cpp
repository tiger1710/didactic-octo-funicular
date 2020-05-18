#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
public:
    FenwickTree(const int& n) : tree(n + 1, 0) { }
    
    int sum(int pos) {
        pos++;
        int ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }
    
    void add(int pos, const int& val) {
        pos++;
        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

class MeasureTime {
private:
    const int ARRMAX = 1000000;
    int N;
    vector<int> arr;
    long long ans;
    
    long long countMoves(void) {
        FenwickTree tree(ARRMAX);
        long long ret = 0;
        for (const int& i : arr) {
            ret += tree.sum(ARRMAX - 1) - tree.sum(i);
            tree.add(i, 1);
        }
        return ret;
    }
    
    void input(void) {
        cin >> N;
        arr = vector<int>(N);
        for (int& i : arr) cin >> i;
    }
    void calc(void) { ans = countMoves(); }
    void output(void) { cout << ans << endl; }
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
    MeasureTime mt;
    while (C--)
        mt.solve();
        
    
    return 0;
}