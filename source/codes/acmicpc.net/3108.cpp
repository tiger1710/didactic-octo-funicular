#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)
using point = pair<int, int>;
using rectangle = pair<point, point>;

vector<rectangle> rect;
vector<bool> visited;
int N;

bool overlapped(const rectangle& a, const rectangle& b) {
    if (
        (a.first.first < b.first.first and a.first.second < b.first.second and
        b.second.first < a.second.first and b.second.second < a.second.second) or
        (b.first.first < a.first.first and b.first.second < a.first.second and
        a.second.first < b.second.first and a.second.second < b.second.second)
    ) {
        return false;
    } else if (
        b.second.first < a.first.first or
        b.second.second < a.first.second or
        a.second.first < b.first.first or
        a.second.second < b.first.second
    ) {
        return false;
    }

    return true;
}

void input(void) {
    cin >> N;
    visited.resize(N + 1, false);
    rect.push_back(
        rectangle(
            point(0, 0),
            point(0, 0)
        )
    );
    REP (i, 0, N) {
        int r1, r2, c1, c2;
        cin >> c1 >> r1 >> c2 >> r2;
        rect.push_back(
            rectangle(
                point(r1, c1),
                point(r2, c2)
            )
        );
    }
}

void dfs(const int& curr) {
    visited[curr] = true;

    const rectangle& currRect = rect[curr];

    REP (i, 0, N + 1) {
        const rectangle& next = rect[i];
        if (not visited[i] and overlapped(currRect, next)) {
            dfs(i);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int raised = -1;
    input();
    REP (i, 0, N + 1) {
        if (not visited[i]) {
            raised++;
            dfs(i);
        }
    }

    cout << raised << endl;

    return 0;
}
