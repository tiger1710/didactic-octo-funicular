#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

class KLIS {
private:
    const long long MAX = 2000000000 + 1;
    int n, k;
    vector<int> lis, cacheLen, S;
    vector<long long> cacheCnt;
    int LIS(const int& start) {
        int& ret = cacheLen[start + 1];
        if (ret not_eq -1) return ret;

        ret = 1;
        for (int next = start + 1; next <= n; next++)
            if (start == -1 or S[start] < S[next])
                ret = max(ret, LIS(next) + 1);
        
        return ret;
    }
    long long count(const int& start) {
        if (LIS(start) == 1) return 1;
        long long& ret = cacheCnt[start + 1];
        if (ret not_eq -1) return ret;

        ret = 0;
        for (int next = start + 1; next <= n; next++) {
            if ((start == -1 or S[start] < S[next]) and
                LIS(start) == LIS(next) + 1)
                ret = min<long long>(MAX, static_cast<long long>(ret) + count(next));
        }
        return ret;
    }
    void reconstruct(const int& start, int skip) {
        if (start not_eq -1) lis.push_back(S[start]);

        vector<pair<int, int>> followers;
        for (int next = start + 1; next <= n; next++) {
            if ((start == -1 or S[start] < S[next]) and
                LIS(start) == LIS(next) + 1)
                followers.push_back(make_pair(S[next], next));
        }
        sort(followers.begin(), followers.end());

        for (const pair<int, int>& follower : followers) {
            int idx = follower.second;
            long long cnt = count(idx);
            if (cnt <= skip) skip -= cnt;
            else {
                reconstruct(idx, skip);
                break;
            }
        }
    }

    void input(void) {
        cin >> n >> k;
        cacheLen = vector<int>(n + 1, -1);
        cacheCnt = vector<long long>(n + 1, -1);
        S = vector<int>(n);
        for (int& i : S) cin >> i;
    }
    void calc(void) {
        reconstruct(-1, k - 1);
    }
    void output(void) {
        cout << lis.size() << endl;
        for (const int& i : lis)
            cout << i << ' ';
        cout << endl;
        lis.clear();
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
    cin.tie(NULL);

    int C; cin >> C;
    KLIS klis;
    while (C--)
        klis.solve();

    return 0;
}