#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
#define point pair<int, int>
using namespace std;

bool isSafe(const int& cur) {
    return 0 <= cur and cur < 100001;
}
int bfs(const int& N, const int& K) {
    vector<int> visitied(100001, 0);
    queue<int> q;
    q.push(N);

    while (not q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == K) return visitied[cur];

        int d[3] = { cur - 1, cur + 1, cur + cur };

        for (int& next : d) {
            if (isSafe(next) and not visitied[next]) {
                visitied[next] = visitied[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);

    int N, K; cin >> N >> K;
    cout << bfs(N, K);


    return 0;
}