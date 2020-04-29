#include <iostream>
#include <map>
#define endl '\n'
using namespace std;
class Nerd2 {
private:
    int N, ans;
    map<int, int> coordinate;

    bool isDominated(const int& r, const int& c) {
        map<int, int>::iterator it = coordinate.lower_bound(c);

        if (it == coordinate.end()) return false;

        return r < it->second;
    }
    void removeDominated(const int& r, const int& c) {
        map<int, int>::iterator it = coordinate.lower_bound(c);
        if (it == coordinate.begin()) return;

        it--;

        while (true) {
            if (it->second > r) break;

            if (it == coordinate.begin()) {
                coordinate.erase(it);
                break;
            }
            else coordinate.erase(it--);
        }
    }
    int registerCoordinate(const int& r, const int& c) {
        if (isDominated(r, c)) return coordinate.size();
        removeDominated(r, c);
        coordinate.insert(make_pair(c, r));
        return coordinate.size();
    }

    void input(void) {
        cin >> N;
        ans = 0;
    }
    void calc(void) {
        while (N--) {
            int r, c; cin >> c >> r;
            ans += registerCoordinate(r, c);
        }
    }
    void output(void) {
        cout << ans << endl;
        coordinate.clear();
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
    Nerd2 nerd2;
    while (C--)
        nerd2.solve();


    return 0;
}