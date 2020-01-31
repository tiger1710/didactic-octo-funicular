#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N;

bool isSafe(pair<int, int>& p) {
    return 0 <= p.first and p.first < N and 0 <= p.second and p.second < N;
}

void dfs(vector<vector<int>>& map, vector<vector<bool>> visited, const int& height, pair<int, int> rc) {
    static int diff[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0 , 1} };
    visited[rc.first][rc.second] = true;

    for (int i = 0; i < 4; i++) {
        pair<int, int> next(rc.first + diff[i][0], rc.second + diff[i][1]);
        if (isSafe(next) and 
            height < map[next.first][next.second] and
            not visited[next.first][next.second]) {
                dfs(map, visited, height, next);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool>(N));


    for (auto& i : map) {
        for (auto& k : i) {
            cin >> k;
        }
    }

    int maxCnt = 0;

    for (int height = 1; height <= 100; height++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                if (height < map[i][k] and not visited[i][k]) {
                    cnt++;
                    dfs(map, visited, height, pair<int, int>(i, k));
                } 
            }
        }
        maxCnt = maxCnt < cnt ? cnt : maxCnt;
        visited = vector<vector<bool>>(N, vector<bool>(N));
    }
    cout << maxCnt << endl;



    return 0;
}