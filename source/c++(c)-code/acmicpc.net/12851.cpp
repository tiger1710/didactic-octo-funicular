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
    int cnt = 0;
    vector<int> visit;
public:
    HS() {
        input();
        if (N not_eq K) calc_bfs();
        else cnt++;
        output();
    }

    void input();
    void calc_bfs();
    void output();

    bool isSafe(const int& p);
    int& visited(const int& p);
};

int main(void) {
    ios_base::sync_with_stdio(false);

    HS hideandseek;

    return 0;
}

void HS::input() {
    cin >> N >> K;
    visit = vector<int>(MAX);
}

void HS::output() {
    cout << visited(K) << endl;
    cout << cnt << endl;
}

void HS::calc_bfs() {
    queue<int> q;
    q.push(N);

    int sec = 0;
    bool chk = false;
    while (not q.empty()) {

        sec++;
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int cur = q.front(); visited(cur) = sec; q.pop();
            const int diff[3] = { -1, 1, cur };

            for (const int& d : diff) {
                int next = cur + d;
                if (next == K) {
                    cnt++;
                    chk = true;
                }
                if (isSafe(next) and (not visited(next))) {
                    q.push(next);
                }
            }
        }
        if (chk) {
            visited(K) = sec;
            break;
        }
    }
}


bool HS::isSafe(const int& p) {
    return 0 <= p and p < MAX;
}

int& HS::visited(const int& p) {
    return visit[p];
}