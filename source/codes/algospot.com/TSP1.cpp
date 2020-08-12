#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define endl '\n'
using namespace std;

class TSP1 {
private:
    const double INF = 1e9+7;
    int N; double ans = INF;

    vector<vector<double>> dist, cache;
    vector<bool> visited;
    double shortestPath(const int& current, const double& currentLength = 0.0) {
        if (not count(visited.begin(), visited.end(), false)) return currentLength;

        double ret = INF;
        for (int next = 0; next < N; next++) {
            if (not visited[next]) {
                visited[next] = true;
                ret = min(ret, shortestPath(next, currentLength + dist[current][next]));
                visited[next] = false;
            }
        }

        return ret;
    }
    double shortestPath2(const int& here, const int& visited) {
        //구현안함. 보정해야됨.
        if (visited == (1 << N) - 1) return dist[here][0];
        double& ret = cache[here][visited];
        if (ret >= 0) return ret;
        ret = INF;
        for (int next = 0; next < N; next++) {
            if (visited bitand (1 << next)) continue;
            double cand = dist[here][next] + shortestPath2(next, visited + (1 << next));
            ret = min(ret, cand);
        }
        return ret;
    }

    void input(void) {
        cin >> N;
        ans = INF;//이거 때문에 2시간 버림..
        dist = vector<vector<double>>(N, vector<double>(N));
        visited = vector<bool>(N, false);
        for (auto& r : dist)
            for (double& c : r)
                cin >> c;
    }
    void calc(void) {
        for (int start = 0; start < N; start++) {
            visited[start] = true;
            ans = min(ans, shortestPath(start));
            visited[start] = false;
        }
    }
    void output(void) {
        cout << ans << endl;
    }

    

public:
    TSP1(void) { (cout << fixed).precision(10); }
    void solve(void) {
        input();
        calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int C; cin >> C;
    TSP1 tsp;
    for (int testCase = 0; testCase < C; testCase++) {
        tsp.solve();
    }

    return 0;
}