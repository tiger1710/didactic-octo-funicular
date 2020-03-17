#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef pair<int, int> min_max;

//https://github.com/kks227/BOJ/blob/master/10200/10265.cpp
//https://coloredrabbit.tistory.com/45
//https://blog.naver.com/kks227/220802519976

class MT {
private:
    int n, k;
    vector<int> students, visited, groupNum;
    vector<bool> checked;
    vector<min_max> sccMinMax;
    vector<vector<int>> scc, dp;
    int ANS;

    int dfs_scc(const int& cur) {
        static stack<int> s;
        static int cnt = 0, gn = 0;
        visited[cur] = ++cnt;
        s.push(cur);

        int next = students[cur], parents = visited[cur];

        if (not visited[next]) parents = min(parents, dfs_scc(next));
        else if (not checked[next]) parents = min(parents, visited[next]);

        if (parents == visited[cur]) {
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
    int find(const int& cur) {//cycle À§Ä¡ÆÄ¾Ç
        const int next = students[cur];
        if (groupNum[cur] == groupNum[next]) {
            return groupNum[cur];
        }
        return find(next);
    }
    int knapsack(const int& cur, const int& capacity) {
        if (cur == sccMinMax.size()) return 0;
        int& result = dp[cur][capacity];
        if (result not_eq -1) return result;

        result = max(result, knapsack(cur + 1, capacity));
        for (int i = sccMinMax[cur].first; i <= sccMinMax[cur].second and i <= capacity; i++) {
            result = max(result, knapsack(cur + 1, capacity - i) + i);
        }
        return result;
    }

    void input(void) {//input & init
        cin >> n >> k;
        students = visited = groupNum = vector<int>(n, 0);
        sccMinMax = vector<min_max>(n);
        checked = vector<bool>(n, false);
        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));

        for (int i = 0, w; i < n; i++) {
            cin >> w;
            students[i] = w - 1;
        }
    }
    void calc(void) {
        for (int i = 0; i < n; i++)
            if (not visited[i])
                dfs_scc(i);

        for (int i = 0; i < n; i++) {//¹­À½´ç ÃÖ¼Ò~ÃÖ´ë °¹¼ö
            int p = find(i);
            int num = groupNum[i];
            if (p == num) sccMinMax[p].first++;//min
            sccMinMax[p].second++;//max
        }

        auto func = [](const min_max& mm) -> bool { return mm == min_max(0, 0); };
        sccMinMax.erase(remove_if(sccMinMax.begin(), sccMinMax.end(), func), sccMinMax.end());
        ANS = knapsack(0, k);
    }
    void output(void) {
        cout << ANS;
    }
public:
    void solve(void) {
        input();
        calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    MT mt;
    mt.solve();

    return 0;
}