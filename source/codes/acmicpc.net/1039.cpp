#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

string N;
int K;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;

    queue<string> q;
    q.push(N);
    REP (i, 0, K) {
        unordered_set<string> s;
        const size_t qSize = q.size();
        REP (size, 0, qSize) {
            const string curr = q.front(); q.pop();
            if (s.find(curr) not_eq s.end()) {
                continue;
            }
            s.insert(curr);

            REP (u, 0, curr.size()) {
                REP (v, u + 1, curr.size()) {
                    string next(curr); swap(next[u], next[v]);
                    if (next.front() not_eq '0') {
                        q.push(next);
                    }
                }
            }
        }
    }

    string ans("0");
    while (not q.empty()) {
        ans = max(ans, q.front());
        q.pop();
    }

    if (ans not_eq "0") {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    

    return 0;
}
