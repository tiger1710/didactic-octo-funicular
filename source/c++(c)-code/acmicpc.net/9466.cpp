#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <string>
#define endl '\n'
#define point pair<int, int>
using namespace std;

enum {notChecked = -1, notGrouped, Grouped};

void dfs(vector<int>& student, vector<bool>& visited, vector<int>& group, int cur) {
    visited[cur] = true;
    int next = student[cur];

    if (visited[next]) {//이미 방문함
        if (group[next] == notChecked) {//하지만 체크가 안됨
            int i = next;               //Cycle 형성
            do {
                group[i] = Grouped;
                i = student[i];
            } while (i not_eq next);
        }
    }
    else dfs(student, visited, group, next);

    //다 방문했는데도 자신이 체크가안됨 : Cycle 제외
    if (group[cur] == notChecked) group[cur] = notGrouped;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int n; cin >> n;
        vector<int> student(n);
        vector<bool> visited(n);
        vector<int> group(n, notChecked); // 1:grouped, 0:not grouped, -1:not checked

        for (int& choose : student) {
            cin >> choose; choose--;
        }

        for (int i = 0; i < n; i++) {
            if (not visited[i]) {
                dfs(student, visited, group, i);
            }
        }

        int cnt = 0;
        for (auto& i : group) {
            if (i == notGrouped) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }


    return 0;
}