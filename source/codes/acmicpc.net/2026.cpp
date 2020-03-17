#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

class Picnic {
private:
    int K, N, F;
    bool ret;
    vector<vector<bool>> areFriends;
    vector<bool> taken;

    bool canPairWith(const int& f) {
        for (int i = 0; i < N; i++)
            if (taken[i] and not areFriends[f][i])
                return false;

        return true;
    }
    bool countPairings(const int& choice, const int& cnt) {
        if (cnt == 0) return true;

        for (int pairWith = choice; pairWith < N; pairWith++) {
            if (not taken[pairWith] and canPairWith(pairWith)) {
                taken[pairWith] = true;
                if (countPairings(pairWith + 1, cnt - 1)) return true;
                taken[pairWith] = false;
            }
        }

        return false;
    }

    void input(void) {
        cin >> K >> N >> F;
        areFriends = vector<vector<bool>>(N, vector<bool>(N, false));
        taken = vector<bool>(N, false);
        for (int i = 0; i < F; i++) {
            int s1, s2; cin >> s1 >> s2;
            areFriends[s1 - 1][s2 - 1] = areFriends[s2 - 1][s1 - 1] = true;
        }
    }
    void calc(void) {
        ret = countPairings(0, K);
    }
    void output(void) {
        if (ret) {
            for (int i = 0; i < N; i++) {
                if (taken[i]) cout << i + 1 << endl;
            }
        }
        else cout << -1 << endl;
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

    Picnic picnic;
    picnic.solve();

    return 0;
}