#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

class CLOCKSYNC {
private:
    int INF = 987654321, ans = INF;
    vector<vector<short>> linked = vector<vector<short>>(10);
    vector<short> clock = vector<short>(16);

    bool areAligned(void) {
        return count_if(clock.begin(), clock.end(), [](const short& t) { return t == 0 or t == 12; }) == 16;
    }
    void push(const int& button) {
        for (short& p : linked[button]) {
            (clock[p] += 3) %= 12;
        }
    }

    void input(void) {
        ans = INF;
        for (short& time : clock) cin >> time;
    }
    int calc(int button) {
        if (button == 10) return areAligned() ? 0 : INF;

        int ret = INF;
        for (int i = 0; i < 4; i++) {
            ret = min(ret, calc(button + 1) + i);
            push(button);
        }

        return ret;
    }
    void output(void) {
        cout << ((ans not_eq INF) ? (ans) : (-1)) << endl;
    }
public:
    CLOCKSYNC(void) {
        linked[0].insert(linked[0].end(), { 0, 1, 2 });
        linked[1].insert(linked[1].end(), { 3, 7, 9, 11 });
        linked[2].insert(linked[2].end(), { 4, 10, 14, 15 });
        linked[3].insert(linked[3].end(), { 0, 4, 5, 6, 7 });
        linked[4].insert(linked[4].end(), { 6, 7, 8, 10 ,12 });
        linked[5].insert(linked[5].end(), { 0, 2, 14 ,15 });
        linked[6].insert(linked[6].end(), { 3, 14, 15 });
        linked[7].insert(linked[7].end(), { 4, 5, 7, 14, 15 });
        linked[8].insert(linked[8].end(), { 1, 2, 3, 4, 5 });
        linked[9].insert(linked[9].end(), { 3, 4, 5, 9, 13 });
    }
    void solve(void) {
        input();
        ans = min(ans, calc(0));
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int C; cin >> C;
    CLOCKSYNC cs;
    for (int testCase = 0; testCase < C; testCase++) {
        cs.solve();
    }

    return 0;
}