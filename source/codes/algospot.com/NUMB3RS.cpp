#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class Numb3rs {
private:
    int n, d, p, q;
    vector<vector<int>> connected;
    vector<vector<double>> cache;
    vector<int> degree;
    vector<double> ans;

    double search(const int& current, const int& day) {
        if (day == 0) return current == p ? 1.0 : 0.0;

        double& ret = cache[current][day];
        if (ret > -0.5) return ret;

        ret = 0.0;
        for (int there = 0; there < n; there++) {
            if (connected[current][there]) {
                ret += (search(there, day - 1) / degree[there]);
            }
        }

        return ret;
    }

    void input(void) {
        cin >> n >> d >> p;
        connected = vector<vector<int>>(n, vector<int>(n));
        cache = vector<vector<double>>(n, vector<double>(d + 1, -0.875));
        degree = vector<int>(n, 0);

        for (int from = 0; from < n; from++) {
            for (int to = 0; to < n; to++) {
                cin >> connected[from][to];
                if (connected[from][to]) {
                    degree[from]++;
                }
            }
        }
    }
    void calc(void) {
        int t; cin >> t;
        while (t--) {
            cin >> q;
            ans.push_back(search(q, d));
        }
    }
    void output(void) {
        for (const double& res : ans) {
            cout << res << ' ';
        }
        ans.clear();
        cout << endl;
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
    (cout << fixed).precision(8);

    int c; cin >> c;
    Numb3rs numbers;

    while (c--)
        numbers.solve();
    

    return 0;
}