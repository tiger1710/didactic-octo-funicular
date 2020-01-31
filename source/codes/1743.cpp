#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, M;

bool isSafe(int& r, int& c) {
    return 0 <= r and r < N and 0 <= c and c < M;
}

int dfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int r, int c) {
    static int diff[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    visited[r][c] = true;
    int size = 1;

    for (int i = 0; i < 4; i++) {
        int nextR = r + diff[i][0], nextC = c + diff[i][1];
        if (isSafe(nextR, nextC) and map[nextR][nextC] and not visited[nextR][nextC]) {
            size += dfs(map, visited, nextR, nextC);
        }
    }

    return size;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    int K; cin >> K;
    vector<vector<int>> map(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M));

    for (int i = 0; i < K; i++) {
        int r, c; cin >> r >> c;
        map[r - 1][c - 1] = 1;
    }

    int maxSize = 0;
    for(int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (map[r][c] and not visited[r][c]) {
                int size = dfs(map, visited, r, c);
                maxSize = maxSize < size ? size : maxSize;
            }
        }
    }
    cout << maxSize << endl;

    return 0;
}