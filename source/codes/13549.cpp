#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
#define point pair<int, int>//first:distance, second:point
using namespace std;

point operator+(const point& p1, const point& p2) {
    return point(p1.first + p2.first, p1.second + p2.second);
}

class HS {
private:
    const int MAX = 100005;
    int N, K;
    vector<bool> visit;
    vector<int> dist;
public:
    HS() {
        this->input();
        this->clac_bfs();
        this->output();
    }

    bool isSafe(const int& p) {
        return 0 <= p and p < MAX;
    }

    void input() {
        cin >> this->N >> this->K;
        this->visit = vector<bool>(MAX);
        this->dist = vector<int>(MAX, MAX);
    }
    void clac_bfs() {
        priority_queue<point, vector<point>, greater<point>> pq;
        pq.push(point(0, this->N));
        dist[this->N] = 0;

        while (not pq.empty()) {
            point cur;

            do {
                cur = pq.top();
                pq.pop();
            } while (not pq.empty() and visit[cur.second]);
            if (visit[cur.second]) break;
        
            visit[cur.second] = true;
            if (cur.second == this->K) return;

            const point diff[3] = { point(0, cur.second), point(1, 1), point(1, -1) };
            for (auto& d : diff) {
                point next = cur + d;
                if  (isSafe(next.second) and next.first < dist[next.second]) {
                    dist[next.second] = next.first;
                    pq.push(next);
                }
            }
        }
    }
    void output() {
        cout << this->dist[this->K];
    }

};

int main(void) {
    ios_base::sync_with_stdio(false);

    HS hideandseek;

    return 0;
}