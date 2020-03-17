#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#define endl '\n'
using namespace std;
typedef pair<int, int> point; //cnt, clipboard

struct point_hash {
    size_t operator() (const point& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

class Emoji {
private:
    int S, ans;
    unordered_map<point, int, point_hash> visit;

    point copy(const point& p) const { return point(p.first, p.first); };
    point paste(const point& p) const { return point(p.first + p.second, p.second); }
    point del(const point& p) const { return point(p.first - 1, p.second); }
    function<point(const Emoji&, const point& p)> fp[3] = { &Emoji::copy, &Emoji::paste, &Emoji::del };

    bool visited(const point& p) { return visit.find(p) not_eq visit.end(); }

    void input(void) { 
        cin >> S;
    }

    void calc(void) {
        queue<point> q;
        q.push(point(1, 0));
        visit[point(1, 0)] = 1;

        while (not q.empty()) {
            point cur = q.front(); q.pop();
            if (cur.first == S) {
                ans = visit[cur] - 1;
                break;
            }
            for (auto& call : fp) {
                point next = call(*this, cur);
                if (next.first >= 0 and
                    not visited(next)) {
                    q.push(next); visit[next] = visit[cur] + 1;
                }
            }
        }
    }
    void output(void) {
        cout << ans;
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

    Emoji e;
    e.solve();

    return 0;
}