#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
typedef pair<string, pair<int, int>> item;

class Packing {
private:
    vector<item> items; 
    vector<vector<int>> cache;
    vector<int> picked;
    int N, W, ans;
    int pack(const int& capacity, const int& n) {
        if (n == this->N) return 0;
        int& ret = cache[capacity][n];
        if (ret not_eq -1) return ret;

        ret = pack(capacity, n + 1);
        if (items[n].second.first <= capacity)
            ret = max(ret,
                    pack(capacity - items[n].second.first, n + 1) + items[n].second.second);

        return ret;
    }
    void reconstruct(const int& capacity, const int& n) {
        if (n == this->N) return;

        if (pack(capacity, n) == pack(capacity, n + 1))
            reconstruct(capacity, n + 1);
        else {
            picked.push_back(n);
            reconstruct(capacity - items[n].second.first, n + 1);
        }
    }

    void input(void) {
        cin >> N >> W;
        items = vector<item>(N);
        cache = vector<vector<int>>(W + 1, vector<int>(N, -1));
        
        for (item& i : items)
            cin >> i.first >> i.second.first >> i.second.second;
            //name, volume, need
    }
    void calc(void) {
        ans = pack(W, 0);
        reconstruct(W, 0);
    }
    void output(void) {
        cout << ans << ' ' << picked.size() << endl;
        for (const int& p : picked)
            cout << items[p].first << endl;
        picked.clear();
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
    Packing p;
    while (C--)
        p.solve();

    return 0;
}