#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
#define point pair<int, int>
using namespace std;

class Box {
private:
    enum { empty = -1, raw, ripe };
    const point diff[4] = { point(-1, 0), point(1, 0), point(0, -1), point(0, 1) };

    int M, N;
    vector<vector<int>> box;
    vector<vector<bool>> visit;
    vector<point> start;
public:
    int isSafe(const point& p);
    vector<bool>::reference visited(const point& p);
    int isAdjacent(const point& p);
    int& boxRef(const point& p);

    void input();
    void calc_bfs();
    int result();
};
point operator+(const point& p1, const point& p2);

int main(void) {
    ios_base::sync_with_stdio(false);

    Box box;
    box.input();
    box.calc_bfs();
    int result = box.result();
    cout << result;


    return 0;
}

void Box::input() {
    cin >> this->M >> this->N;
    this->box = vector<vector<int>>(N, vector<int>(M));
    this->visit = vector<vector<bool>>(N, vector<bool>(M));
    for (int r = 0; r < this->N; r++) {
        for (int c = 0; c < this->M; c++) {
            cin >> this->box[r][c];
            if (this->box[r][c] == this->ripe) {
                this->start.push_back(point(r, c));
            }
        }
    }
}

void Box::calc_bfs() {
    queue<point> q;
    for (point& p : this->start) {//put all riped tomato
        q.push(p);
        this->visited(p) = true;
    }

    while (not q.empty()) {
        point cur = q.front(); q.pop();

        for (const point& d : this->diff) {
            point next = cur + d;
            if (this->isSafe(next) and this->isAdjacent(next) and (not visited(next))) {
                q.push(next);
                boxRef(next) = boxRef(cur) + 1;
                visited(next) = true;;
            }
        }
    }
}

int Box::result() {
    int chk = 0;
    for (auto& r : this->box) {
        for (auto& c : r) {
            if (c == raw) return -1;
            chk = chk < c ? c : chk;
        }
    }
    return chk - 1;
}

int& Box::boxRef(const point& p) {
    return this->box[p.first][p.second];
}

int Box::isSafe(const point& p) {
    return 0 <= p.first and p.first < this->N and 0 <= p.second and p.second < this->M;
}

vector<bool>::reference Box::visited(const point& p) {
    return visit[p.first][p.second];
}

int Box::isAdjacent(const point& p) {
    return this->box[p.first][p.second] not_eq this->empty;
}

point operator+(const point& p1, const point& p2) {
    return point(p1.first + p2.first, p1.second + p2.second);
}