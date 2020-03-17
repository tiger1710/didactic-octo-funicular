#include <iostream>
#include <vector>
#include <queue>
#define endl '\n' 
using namespace std;

class HS {
private:
    const int MAX = 100001;
    int N, K;
    vector<int> visited;
    vector<int> previous;
public:
    void solve(void) {
        input();
        calc_bfs();
        cout << visited[K] - 1 << endl; 
        output(K);
    }

    bool isSafe(const int& p) {
        return 0 <= p and p < MAX;
    }

    void input(void) {
        cin >> N >> K;
        visited = previous = vector<int>(MAX);
        previous[N] = -1;
    }
    void calc_bfs(void) {
        queue<int> q;
        q.push(N);
        visited[N] = 1;

        while (not q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == K) break;     
            for (const int& d : { cur, 1, -1 } ) {
                int next = cur + d;
                if (isSafe(next) and not visited[next]) {
                    q.push(next);
                    visited[next] = visited[cur] + 1;
                    previous[next] = cur;
                }
            }
        }
    }
    void output(const int& p) {
        if (p not_eq -1) {
            output(previous[p]);
            cout << p << ' ';
        }
    }
};
 
 

 
int main(void) {
    ios_base::sync_with_stdio(false);

    HS HideAndSeek;
    HideAndSeek.solve();
 
    return 0;
}
