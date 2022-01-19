#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define endl '\n'
using namespace std;

//https://algospot.com/judge/submission/detail/166203
class LIS {
private:
    enum { A, B };
    const long long NEGINF = numeric_limits<long long>::min();
    int n, m, ans;
    vector<int> sequence[2];
    vector<vector<int>> cache;

    int jlis(const int& indexA, const int& indexB) {
        int& ret = cache[indexA + 1][indexB + 1];
        if (ret) return ret;

        long long a = indexA not_eq -1 ? sequence[A][indexA] : NEGINF;
        long long b = indexB not_eq -1 ? sequence[B][indexB] : NEGINF;
        long long maxElement = max(a, b);
        for (int nextA = indexA + 1; nextA < n; nextA++) {
            if (maxElement < sequence[A][nextA])
                ret = max(ret, jlis(nextA, indexB) + 1);
        }
        for (int nextB = indexB + 1; nextB < m; nextB++) {
            if (maxElement < sequence[B][nextB])
                ret = max(ret, jlis(indexA, nextB) + 1);
        }

        return ret;
    }
    

    void input(void) {
        cin >> n >> m;
        sequence[A] = vector<int>(n);//A
        sequence[B] = vector<int>(m);//B
        cache = vector<vector<int>>(n + 1, vector<int>(m + 1));//dp
        for (auto& r : sequence)
            for (int& c : r)
                cin >> c;
        
    }
    void calc(void) {
        ans = jlis(-1, -1);
    }
    void output(void) {
        cout << ans << endl;
    }
public:
    void solve(void) {
        input();
        calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C; cin >> C;
    LIS lis;
    for (int testCase = 0; testCase < C; testCase++) {
        lis.solve();
    }
    
    return 0;
}