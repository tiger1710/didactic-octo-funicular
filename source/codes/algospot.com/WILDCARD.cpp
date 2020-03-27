#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

class WildCard {
private:
    string w, s;

    int N;
    vector<string> ans;
    vector<vector<int>> cache;

    int match(size_t wpos, size_t spos) {
        int& ret = cache[wpos][spos];
        if (ret not_eq -1) return ret;

        while (wpos < w.size() and spos < s.size() and (w[wpos] == '?' or w[wpos] == s[spos])) {
            wpos++, spos++;
        }

        if (wpos == w.size()) return ret = (spos == s.size());

        if (w[wpos] == '*')
            for (size_t skip = 0; spos + skip <= s.size(); skip++)
                if (match(wpos + 1, spos + skip))
                    return ret = true;

        return ret = false;
    }
    int matchOptimize(size_t wpos, size_t spos) {
        int& ret = cache[wpos][spos];
        if (ret not_eq -1) return ret;

        if (wpos < w.size() and
            spos < s.size() and
            (w[wpos] == '?' or w[wpos] == s[spos]))
            return matchOptimize(wpos + 1, spos + 1);

        if (wpos == w.size()) return ret = (spos == s.size());

        if (w[wpos] == '*')
            if (matchOptimize(wpos + 1, spos) or
                (spos < s.size() and matchOptimize(wpos, spos + 1)))
                return ret = true;

        return ret = false;
    }

    void input(void) {
        cin >> w >> N;
    }
    void calc(void) {
        for (int i = 0; i < N; i++) {
            cin >> s;
            cache = vector<vector<int>>(101, vector<int>(101, -1));
            if (matchOptimize(0, 0)) ans.push_back(s);
        }
        sort(ans.begin(), ans.end());
    }
    void output(void) {
        for (const string& str : ans) cout << str << endl;
        ans.clear();
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
    WildCard wc;
    for (int testCase = 0; testCase < C; testCase++) {
        wc.solve();
    }


    return 0;
}