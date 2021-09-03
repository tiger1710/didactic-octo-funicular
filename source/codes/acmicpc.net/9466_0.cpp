#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

vector<int> student;
vector<bool> visited, finished, grouped;

void dfs(const int& curr) {
    visited[curr] = true;

    int next = student[curr];
    if (not visited[next]) {
        dfs(next);
    } else if (not finished[next]) {
        grouped[curr] = true;
        while (curr not_eq next) {
            grouped[next] = true;
            next = student[next];
        }
    }
    finished[curr] = true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    REP (test, 0, T) {
        int n; cin >> n;
        student = vector<int>(n);
        visited = finished = grouped = vector<bool>(n, false);
        REP (i, 0, n) {
            int s; cin >> s;
            student[i] = s - 1;
        }
        REP (i, 0, n)
            if (not visited[i])
                dfs(i);
        
        cout << count(ALL(grouped), false) << endl;
    }


    return 0;
}
