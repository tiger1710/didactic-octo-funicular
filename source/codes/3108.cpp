#include <iostream>
#include <vector>
#include <unordered_map>
#define endl '\n'
using namespace std;

typedef pair<int, int> point;
typedef pair<point, point> rectangle;

istream& operator>>(istream& in, point& p) { return in >> p.first >> p.second; }
istream& operator>>(istream& in, rectangle& r) { return in >> r.first >> r.second; }

struct rectangle_hash {
    size_t operator() (const rectangle& p) const {//해쉬맵용 hash임시함수
        return (hash<int>()(p.first.first) ^ hash<int>()(p.first.second)) ^ (hash<int>()(p.second.first) ^ hash<int>()(p.second.second));
    }
};

class Logo {
private:
    int N;
    int cnt = -1;
    vector<rectangle> rect;
    unordered_map<rectangle, bool, rectangle_hash> visited;

    bool inner(const rectangle& a, const rectangle& b) {// a 안에 b(내포)
        return (a.first.first < b.first.first and b.second.first < a.second.first) and 
                (a.first.second < b.first.second and b.second.second < a.second.second);
    }
    bool outter(const rectangle& a, const rectangle& b) {//b 안에 a(외포) 또는, a 밖에 b(상하좌우 위치)
        return ((b.first.first < a.first.first and a.second.first < b.second.first) and 
                (b.first.second < a.first.second and a.second.second < b.second.second)) or
                b.second.first < a.first.first or//상
                a.second.first < b.first.first or//하
                b.second.second < a.first.second or//좌
                a.second.second < b.first.second;//우
    }
    bool connected(const rectangle& a, const rectangle& b) {
        return not inner(a, b) and not outter(a, b);
    }
    void dfs(const rectangle& cur) {
        visited[cur] = true;

        for (auto& next : rect) {
            if (not visited[next] and connected(cur, next)) {
                dfs(next);
            }
        }
    }

    void input(void) {
        cin >> N;
        rect.push_back(rectangle(point(0, 0), point(0, 0)));
        for (int i = 0; i < N; i++) {
            rectangle r; cin >> r;
            rect.push_back(r);
            visited[r] = false;
        }
    }
    void calc(void) {
        for (auto& r : rect) {
            if (not visited[r]) {
                dfs(r); cnt++;
            }
        }
    }
    void output(void) {
        cout << cnt;
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

    Logo logo;
    logo.solve();

    return 0;
}