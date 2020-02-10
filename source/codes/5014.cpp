#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
#define point pair<int, int>
using namespace std;

class Building {
private:
    vector<int> visit;
    int F, S, G, U, D;
public:
    void input();
    void calc_bfs();
    void output();
    Building() {
        this->input();
        this->calc_bfs();
        this->output();
    }

    int isSafe(const int& p);
    int& visited(const int& p);
};

int main(void) {
    ios_base::sync_with_stdio(false);
    Building building;

    return 0;
}

void Building::input() {
    cin >> this->F >> this->S >> this->G >> this->U >> this->D;
    this->visit = vector<int>(this->F);
    this->S--; this->G--;
}

int Building::isSafe(const int& p) {
    return 0 <= p and p < this->F;
}

int& Building::visited(const int& p) {
    return this->visit[p];
}

void Building::output() {
    int result = visited(this->G);
    
    switch (result) {
    case 0:
        cout << "use the stairs";
        break;
    default:
        cout << result - 1;
        break;
    }
}

void Building::calc_bfs() {
    static const int diff[2] = { this->U, -this->D };
    queue<int> q;
    q.push(this->S);
    visited(this->S) = 1;

    while (not q.empty()) {
        int cur = q.front(); q.pop();

        for (const int& d : diff) {
            int next = cur + d;
            if (isSafe(next) and (not visited(next))) {
                q.push(next);
                visited(next) = visited(cur) + 1;
            }
        }
    }
}