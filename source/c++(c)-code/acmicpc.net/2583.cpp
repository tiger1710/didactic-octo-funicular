#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N, K; //M:row, N:col, K:rectCnt

void paint(vector<vector<int>>& area, pair<int, int>& ld, pair<int, int>& ru) {
    for (int i = ld.first; i < ru.first; i++) {
        for (int k = ld.second; k < ru.second; k++) {
            area[i][k] = 0;
        }
    }
}

bool isSafe(pair<int, int>& pos) {
    return 0 <= pos.first and pos.first < M and 0 <= pos.second and pos.second < N;
}

int dfs(vector<vector<int>>& area, vector<vector<bool>>& visited, pair<int, int> pos) {
    static pair<int,int> diff[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int size = 1;
    visited[pos.first][pos.second] = true;
    for (int i = 0; i < 4; i++) {
        pair<int, int> next(pos.first + diff[i].first, pos.second + diff[i].second);
        if (isSafe(next) and area[next.first][next.second] and not visited[next.first][next.second]) {
            size += dfs(area, visited, next);
        }
    }
    return size;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    vector<vector<int>> area(M, vector<int>(N, 1));
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    
    for (int i = 0; i < K; i++) {
        pair<int, int> leftdown, rightup;
        cin >> leftdown.first >> leftdown.second;
        cin >> rightup.first >> rightup.second;
        paint(area, leftdown, rightup);
    }

    int cnt = 0;
    vector<int> size;
    for (int i = 0; i < M; i++) {
        for (int k = 0; k < N; k++) {
            if (area[i][k] and not visited[i][k]) {
                cnt++;
                size.push_back(dfs(area, visited, pair<int, int>(i, k)));
            }
        }
    }
    sort(size.begin(), size.end());
    cout << cnt << endl;
    for (int& i : size) cout << i << ' ';

    return 0;
}
