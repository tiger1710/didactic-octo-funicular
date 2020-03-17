#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

class Picnic {
private:
    int n, m;
    int ans = 0;

    vector<vector<bool>> areFriends;
    vector<bool> taken;

    int countPairing(void) {
        int firstFree = find(taken.begin(), taken.end(), false) - taken.begin();
        if (firstFree == n) return 1;

        int ret = 0;
        for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
            if (not taken[pairWith] and areFriends[firstFree][pairWith]) {
                taken[firstFree] = taken[pairWith] = true;
                ret += countPairing();
                taken[firstFree] = taken[pairWith] = false;
            }
        }
        return ret;
    }

    void input(void) {
        cin >> n >> m;
        areFriends = vector<vector<bool>>(n, vector<bool>(n, false));
        taken = vector<bool>(n, false);
        for (int i = 0; i < m; i++) {
            int s1, s2; cin >> s1 >> s2;
            areFriends[s1][s2] = areFriends[s2][s1] = true;
        }
    }
    void calc(void) {
        ans = countPairing();
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int C; cin >> C;
    Picnic picnic;
    for (int i = 0; i < C; i++) {
        picnic.solve();
    }

    return 0;
}