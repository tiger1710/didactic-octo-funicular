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
    bool operator!=(const Rampart& rampart) const {
        return this->center not_eq rampart.center or
                this->r not_eq rampart.r;
    }
    bool isParentOf(const Rampart& child, const vector<Rampart>& rampart) {
        if (not enclose(child)) return false;
        for (const Rampart& i : rampart) {
            if (i not_eq *this and i not_eq child and
                enclose(i) and i.enclose(child)) return false;
        }
        return true;
    }
};

class Fortress {
private:
    int N, ans;
    vector<Rampart> rampart;

    int height(const int& root) {
        int h1 = 0, h2 = 0;
        int h = 0;

        for (int i = 1; i < N; i++) {
            if (rampart[root].isParentOf(rampart[i], rampart)) {
                int t = height(i);
                if (h1 < t) { h2 = h1; h1 = t; }
                else if (h2 < t) h2 = t;
                h = max(h, t);
            }
        }

        if (h < h1 + h2) return h1 + h2;
        else return h + 1;
    }
    void input(void) {
        cin >> N;
        rampart = vector<Rampart>(N);
        for (Rampart& i : rampart) cin >> i;
    }
    void calc(void) {
        ans = height(0);
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