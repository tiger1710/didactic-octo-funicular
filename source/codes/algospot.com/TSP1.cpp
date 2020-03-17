#include <iostream>
#include <vector>
#include <limits>
#define endl '\n'
using namespace std;

class TSP1 {
private:
    const double INF = 1e9;
    int N; double ans = INF;
    vector<vector<double>> dist;
    vector<bool> visited;
    vector<int> path;

    void input(void) {
        cin >> N;
        dist = vector<vector<double>>(N, vector<double>(N));
        visited = vector<bool>(N);
        for (auto& r : dist)
            for (double& c : r)
                cin >> c;
    }
    void calc(void) {
        for (int start = 0; start < N; start++) {
            ans = min(ans, shortestPath(start, 0.0));
        }
    }
    void output(void) {
        cout << ans << endl;
    }

    double shortestPath(const int& current, const double& currentLength) {
        if (path.size() == N) return currentLength;

        double ret = INF;
        for (int next = 0; next < N; next++) {
            if (not visited[next]) {
                visited[next] = true; path.push_back(next);
                ret = min(ret, shortestPath(next, currentLength + dist[current][next]));
                visited[next] = false; path.pop_back();
            }
        }

        return ret;
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