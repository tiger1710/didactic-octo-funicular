#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;
class Calc;

class Bottle {
private:
    int volume[3];
    int buket[3] = { 0, 0, 0 };

    void input(void) {
        for (int& i : volume) {
            cin >> i;
        }
        buket[0] = buket[1] = 0;
        buket[2] = volume[2];
    }
public:
    friend Calc;
    int Abuket(void) {
        return buket[0];
    }
    int Cbuket(void) {
        return buket[2];
    }

    void pour(const int& from, const int& to) {
        if (volume[to] - buket[to] >= buket[from]) {
            buket[to] += buket[from];
            buket[from] = 0;
        }
        else {
            buket[from] -= (volume[to] - buket[to]);
            buket[to] = volume[to];
        }
    }

    Bottle(void) {
        input();
    }
};

class Calc{
private:
    Bottle start;
    vector<vector<vector<bool>>> visit;
    vector<int> ans;

    vector<bool>::reference visited(const Bottle& b) {
        return visit[b.buket[0]][b.buket[1]][b.buket[2]];
    }
    

    void init(void) {
        visit = vector<vector<vector<bool>>>(201, vector<vector<bool>>(201, vector<bool>(201)));
    }
    void calc(void) {
        queue<Bottle> q;
        q.push(start); visited(start) = true;
        ans.push_back(start.Cbuket());

        while (not q.empty()) {
            Bottle cur = q.front(); q.pop();
            for (int from = 0; from < 3; from++) {
                for (int to = 0; to < 3; to++) {
                    if (from == to) continue;
                    Bottle next = cur; next.pour(from, to);
                    if (not visited(next)) {
                        visited(next) = true;
                        q.push(next);
                        if (next.Abuket() == 0) ans.push_back(next.Cbuket());
                    }
                }
            }
        }
    }
    void output(void) {
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        for (int& i : ans) {
            cout << i << ' ';
        }
    }
public:
    void solve(void) {
        init();
        calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);

    Calc calc;
    calc.solve();

    return 0;
}