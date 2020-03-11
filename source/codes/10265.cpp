#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MT {
private:
    int n, k;
    vector<int> students, visited, groupNum;
    vector<bool> checked, sccChoice;
    vector<vector<int>> scc;

    int dfs(const int& cur) {
        static stack<int> s;
        static int cnt = 0, gn = 0;
        visited[cur] = ++cnt;
        s.push(cur);

        int next = students[cur], parents = visited[cur];

        if (not visited[next]) parents = min(parents, dfs(next));
        else if (not checked[next]) parents = min(parents, visited[next]);

        if (parents == cur) {
            vector<int> group;
            while (true) {
                int t = s.top(); s.pop();
                group.push_back(t);
                checked[t] = true;
                groupNum[t] = gn;

                if (t == cur) break;
            }

            scc.push_back(group);
            gn++;
        }

        return parents;
    }
    int knapsack(const int& cur, const int& capacity, vector<bool> choice) {
        if (cur == scc.size()) return;

        int result = 0;
        if (scc[cur].size() <= capacity) {
            result = knapsack(cur + 1, capacity - scc[cur].size(), choice) + scc[cur].size();
        }
        result = max(result, knapsack(cur + 1, capacity, choice));
        return result;
    }

    void input(void) {
        cin >> n >> k;
        students = visited = groupNum = vector<int>(n, 0);
        checked = vector<bool>(n, false);

        for (int i = 0, w; i < n; i++) {
            cin >> w;
            students[w - 1] = i;
        }
    }
    void calc(void) {
        for (int i = 0; i < n; i++) dfs(i);
        sccChoice = vector<bool>(scc.size(), false);
    }
public:
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);



    return 0;
}