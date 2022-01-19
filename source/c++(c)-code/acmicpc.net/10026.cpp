#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int N;

bool isSafe(pair<int, int>& cur) {
    return 0 <= cur.first and cur.first < N and 0 <= cur.second and cur.second < N;
}

pair<int, int>operator+(pair<int, int>& p1, pair<int, int>& p2) {
    return pair<int, int>(p1.first + p2.first, p1.second + p2.second);
}

void normal(vector<vector<char>>& picture, vector<vector<bool>>& normalVisited, pair<int, int> cur) {
    static pair<int,int> diff[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    normalVisited[cur.first][cur.second] = true;
    for (int i = 0; i < 4; i++) {
        pair<int, int> next = cur + diff[i];
        if (isSafe(next) and not normalVisited[next.first][next.second]
             and picture[cur.first][cur.second] == picture[next.first][next.second]) {
            normal(picture, normalVisited, next);
        }
    }
}

void abnormal(vector<vector<char>>& picture, vector<vector<bool>>& abnormalVisited, pair<int, int> cur) {
    static pair<int,int> diff[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    abnormalVisited[cur.first][cur.second] = true;
    for (int i = 0; i < 4; i++) {
        pair<int, int> next = cur + diff[i];
        if (isSafe(next) and not abnormalVisited[next.first][next.second]
             and (picture[cur.first][cur.second] == picture[next.first][next.second]
             or (picture[cur.first][cur.second] == 'R' and picture[next.first][next.second] == 'G')
             or (picture[cur.first][cur.second] == 'G' and picture[next.first][next.second] == 'R')
             )) {
            abnormal(picture, abnormalVisited, next);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<vector<char>> picture(N, vector<char>(N));
    vector<vector<bool>> normalVisited(N, vector<bool>(N, false));
    vector<vector<bool>> abnormalVisitied(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> picture[i][k];
        }
    }

    int normalCnt = 0, abnormalCnt = 0;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (not normalVisited[i][k]) {
                normalCnt++;
                normal(picture, normalVisited, pair<int, int>(i, k));
            }
            if (not abnormalVisitied[i][k]) {
                abnormalCnt++;
                abnormal(picture, abnormalVisitied, pair<int, int>(i, k));
            }
        }
    }
    cout << normalCnt << ' ' << abnormalCnt << endl;

    return 0;
}
