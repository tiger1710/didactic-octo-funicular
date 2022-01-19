#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

const int square(const int& i) { return i * i; }

class Rampart {
private:
    point center;
    int r;
    static int squareDist(const point& a, const point& b) {
        return square(a.first - b.first) +
                square(a.second - b.second);
    }
    bool enclose(const Rampart& child) const {
        return this->r > child.r and
            squareDist(this->center, child.center) < square(this->r - child.r);
    }
public:
    friend istream& operator>>(istream& i, Rampart& rampart) {
        return i >> rampart.center.first >> rampart.center.second >> rampart.r;
    }
    bool operator<(const Rampart& rampart) const { return this->r < rampart.r; }
    bool isChildOf(const Rampart& parent) const {
        return parent.enclose(*this);
    }
};

class Fortress {
private:
    int N, ans, leafToLeaf;
    vector<Rampart> rampart;
    vector<vector<int>> tree;

    int height(const int& root) {
        int h = 0;
        vector<int> heights;
        for (const int& child : tree[root]) {
            heights.push_back(height(child));
        }
        if (heights.empty()) return 0;
        sort(heights.begin(), heights.end());

        if (2 <= heights.size())
            leafToLeaf = max(leafToLeaf,
                                2 + heights[heights.size() - 1] + heights[heights.size() - 2]);

        return heights.back() + 1;
    }

    void init(void) {
        leafToLeaf = 0;
        sort(rampart.begin(), rampart.end());
        for (int child = 0; child < N; child++)
            for (int parent = child + 1; parent < N; parent++)
                if (rampart[child].isChildOf(rampart[parent])) {
                    tree[parent].push_back(child);
                    break;
                }
    }
    void input(void) {
        cin >> N;
        rampart = vector<Rampart>(N);
        tree = vector<vector<int>>(N);
        for (Rampart& i : rampart) cin >> i;
    }
    void calc(void) {
        init();
        ans = max(leafToLeaf, height(N - 1));
    }
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
    Fortress fortress;
    while (C--)
        fortress.solve();

    return 0;
}