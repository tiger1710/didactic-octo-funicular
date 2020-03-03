#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//https://justicehui.github.io/medium-algorithm/2018/08/30/01BFS/
//https://justicehui.github.io/koi/2019/03/09/BOJ2665/ 참고

typedef pair<int, int> point;
point operator+(const point& a, const point& b) { return point(a.first + b.first, a.second + b.second); }

class Makemaze {
private:
    enum { black, white };
    point start, end;
    int n;
    vector<vector<char>> room;
    vector<vector<bool>> visit;

    vector<bool>::reference visited(const point& p) { return visit[p.first][p.second]; }

    void input(void) {
        (cin >> n).ignore();
        room = vector<vector<char>>(n, vector<char>(n));
        for (auto& r : room) {
            for (char& c : r)
                c = cin.get();
            cin.ignore();
        }
        start = point(0, 0); end = point(n - 1, n - 1);
    }
    void calc(void) {
        int __break = 0;//부실 벽 갯수
        do {//bfs
            visit = vector<vector<bool>>(n, vector<bool>(n));
            queue<point> q; q.push(start); visited(start) = 1;
            while (not q.empty()) {

            }
        } while (not visited(end));
    }
public:
};

int main(void) {
    ios_base::sync_with_stdio(false);

    return 0;
}