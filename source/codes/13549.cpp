#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
#define point pair<int, int>
using namespace std;

class HS {
private:
    const int MAX = 100001;
    int N, K;
    vector<int> visit;
public:
    HS() {
        this->input();
        if (this->N not_eq this->K) this->clac_bfs();
        else visit[this->K] = 1;
        this->output();
    }

    bool isSafe(const int& p) {
        return 0 <= p and p < MAX;
    }

    void input() {
        cin >> this->N >> this->K;
        this->visit = vector<int>(MAX);
    }
    void clac_bfs() {
        queue<int> q;
        q.push(this->N);
        this->visit[this->N] = 1;

        while (not q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == this->K) break;

            if (isSafe(cur + cur) and not visit[cur + cur]) {
                q.push(cur + cur);
                this->visit[cur + cur] = visit[cur];
            }
            if (isSafe(cur + 1) and not visit[cur + 1]) {
                q.push(cur + 1);
                this->visit[cur + 1] = visit[cur] + 1;
            }
            if (isSafe(cur - 1) and not visit[cur - 1]) {
                q.push(cur - 1);
                this->visit[cur - 1] = visit[cur] + 1;
            }

        }
    }
    void output() {
        cout << this->visit[this->K] - 1;
    }

};

int main(void) {
    ios_base::sync_with_stdio(false);

    HS hideandseek;

    return 0;
}