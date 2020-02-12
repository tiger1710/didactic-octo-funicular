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
        this->input();
        this->calc_bfs();
        cout << this->visited[this->K] - 1 << endl; 
        this->output(this->K);
    }

    bool isSafe(const int& p) {
        return 0 <= p and p < this->MAX;
    }

    void input(void) {
        cin >> this->N >> this->K;
        visited = previous = vector<int>(this->MAX);
        previous[this->N] = -1;
    }
    void calc_bfs(void) {
        queue<int> q;
        q.push(this->N);
        visited[this->N] = 1;

        while (not q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == this->K) break;     
            for (const int& d : { cur, 1, -1 } ) {
                int next = cur + d;
                if (this->isSafe(next) and not visited[next]) {
                    q.push(next);
                    this->visited[next] = this->visited[cur] + 1;
                    this->previous[next] = cur;
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
