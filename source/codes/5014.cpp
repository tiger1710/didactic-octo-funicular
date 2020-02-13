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
        input();
        calc_bfs();
        output();
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
    cin >> F >> S >> G >> U >> D;
    visit = vector<int>(F);
    S--; G--;
}

int Building::isSafe(const int& p) {
    return 0 <= p and p < F;
}

int& Building::visited(const int& p) {
    return visit[p];
}

void Building::output() {
    int result = visited(G);
    
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
    static const int diff[2] = { U, -D };
    queue<int> q;
    q.push(S);
    visited(S) = 1;

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