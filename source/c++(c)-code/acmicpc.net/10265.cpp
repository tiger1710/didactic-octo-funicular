#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

//https://github.com/kks227/BOJ/blob/master/10200/10265.cpp
//https://coloredrabbit.tistory.com/45
//https://blog.naver.com/kks227/220802519976

vector<int> visited, participant;
vector<bool> finished;
vector<vector<int> > scc, dp;

int n, k;
int cnt = 1;

int dfs(const int& curr) { // scc tarjan
    static stack<int> s;
    visited[curr] = cnt++;
    s.push(curr);

    int parent = visited[curr];
    const int& next = participant[curr];

    if (not visited[next]) { // not visited
        parent = min(parent, dfs(next));
    } else if (not finished[next]) {
        parent = min(parent, visited[next]);
    }

    if (parent == visited[curr]) {
        vector<int> g; // group
        while (true) {
            const int t = s.top(); s.pop();
            g.push_back(t);
            finished[t] = true;

            if (t == curr) break;
        }
        scc.push_back(g);
    }

    return parent;
}

/*
int knapsack(const int& curr, const int& capacity) {
    if (curr == scc.size()) return 0;
    int& result = dp[curr][capacity];
    if (result not_eq -1) return result;

    result = max(result, knapsack(curr + 1, capacity));
    for (int i = sccMinMax[curr].first; i <= sccMinMax[curr].second and i <= capacity; i++) {
        result = max(result, knapsack(curr + 1, capacity - i) + i);
    }
    return result;
}
*/

void input(void) {
    cin >> n >> k;
    visited.resize(n, 0);
    participant.resize(n);
    finished.resize(n, false);
    dp.resize(n, vector<int>(k, -1));
    for (int& i : participant) {
        cin >> i; i--;
    }
}


void calc(void) {
    REP (i, 0, n) {
        if (not visited[i]) {
            dfs(i);
        }
    }
    sort(scc.begin(), scc.end(),
        [](const vector<int>& a, const vector<int>& b) -> bool {
            return a.size() > b.size();
        }
    );

}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    input();
    calc();

    return 0;
}