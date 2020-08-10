#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#define endl '\n'
using namespace std;

class Dragon {
private:
    const int MAX = 1000000000 + 1;
    const string EXPAND_X = "X+YF";
    const string EXPAND_Y = "FX-Y";
    vector<int> length;
    int n, p, l;
    string ans;

    char expand(const string& dragonCurve, const int& generations, int skip) {
        if (generations == 0) {
            assert(skip < dragonCurve.size());
            return dragonCurve[skip];
        }
        for (int i = 0; i < dragonCurve.size(); i++)
            if (dragonCurve[i] == 'X' or dragonCurve[i] == 'Y') {
                if (skip >= length[generations])
                    skip -= length[generations];
                else if (dragonCurve[i] == 'X')
                    return expand(EXPAND_X, generations - 1, skip);
                else
                    return expand(EXPAND_Y, generations - 1, skip);
            }
            else if (skip > 0)
                skip--;
            else
                return dragonCurve[i];
            
        return '#';
    }

    void input(void) {
        cin >> n >> p >> l;
        p--;
    }
    void calc(void) {
        for (int i = 0; i < l; i++)
            ans.push_back(expand("FX", n, p + i));
    }
    void output(void) {
        cout << ans << endl;
        ans.clear();
    }
public:
    Dragon(void) {
        length = vector<int>(51);
        length[0] = 1;
        for (int i = 1; i <= 50; i++)
            length[i] = min(MAX, (length[i - 1] << 1) + 2);
    }
    void solve(void) {
        input();
        calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int c; cin >> c;
    Dragon d;
    while (c--)
        d.solve();

    return 0;
}