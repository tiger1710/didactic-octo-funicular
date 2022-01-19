#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

using point = pair<int, char>;
vector<bool> visited;
vector<point> before;
const static char op[4] = { 'D', 'S', 'L', 'R' };
int A, B;

int L(int reg) {
    int carry = reg / 1000;
    reg -= (carry * 1000);
    reg *= 10;
    reg += carry;
    return reg;
}

int R(int reg) {
    int carry = reg % 10;
    reg /= 10;
    reg += carry * 1000;
    return reg;
}

void bfs(void) {
    queue<int> q;
    q.push(A);
    visited[A] = true;
    before[A] = point(-1, endl);

    while (not q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == B) {
            return;
        }

        int dslr[4] = {
            ((curr << 1) % 10000),
            (curr not_eq 0 ? curr - 1 : 9999),
            L(curr),
            R(curr)
        };
        
        REP (i, 0, 4) {
            if (not visited[dslr[i]]) {
                q.push(dslr[i]);
                visited[dslr[i]] = true;
                before[dslr[i]] = point(curr, op[i]);
            }
        }
    }
}

void print(const int& curr) {
    if (curr not_eq -1) print(before[curr].first);
    if (curr == -1) return;
    cout << before[curr].second;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    size_t T; cin >> T;
    while (T--) {
        cin >> A >> B;
        visited = vector<bool>(10000, false);
        before = vector<point>(10000);
        bfs();
        print(B); cout << endl;
    }
    


    return 0;
}
