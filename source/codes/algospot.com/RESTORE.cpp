#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

class Restore {
private:
    int k;
    string ans;
    vector<string> word;
    vector<vector<int>> cache, overlap;

    void init(void) {
        for (int last = 0; last < word.size(); last++)
            for (int next = 0; next < word.size(); next++)
                if (last not_eq next and
                    word[last].find(word[next]) not_eq string::npos) {
                        word.erase(word.begin() + next);
                        last--;
                        break;
                    }
    }

    int restore(const int& last, const int& used) {
        if (used == (1 << k) - 1) return 0;
        
        int& ret = cache[last][used];
        if (ret not_eq -1) return ret;

        ret = 0;
        for (int next = 0; next < k; next++)
            if ((used bitand (1 << next)) == 0) {
                int cand = overlap[last][next] + restore(next, used + (1 << next));
                ret = max(ret, cand);
            }
        
        return ret;
    }
    int d(const string& a, const string& b) {
        int maxOverlap = 0, l = a.length() < b.length() ? a.length() : b.length();
        for (int i = 0; i < l; i++) {
            string Asubstr = a.substr(a.length() - 1 - i);
            string Bsubstr = b.substr(0, i + 1);
            if (Asubstr == Bsubstr)
                maxOverlap = Asubstr.length();
        }
        return maxOverlap;
    }

    string reconstruct(const int& last, const int& used) {
        if (used == (1 << k) - 1) return "";
        for (int next = 0; next < k; next++) {
            if (used bitand (1 << next)) continue;
            int ifUsed = restore(next, used + (1 << next)) +
                            overlap[last][next];
            if (restore(last, used) == ifUsed)
                return (word[next].substr(overlap[last][next]) +
                        reconstruct(next, used + (1 << next)));
        }
        return "****oops****";
    }

    void input(void) {
        cin >> k;
        word = vector<string>(k);
        for (string& str : word) cin >> str;
        init();
        cache = vector<vector<int>>(k + 1, vector<int>(1 << k, -1));
        overlap = vector<vector<int>>(k, vector<int>(k));
        overlap.push_back(vector<int>(k, 0));

        //overlap[a][b] = a의 접미사, b의 접두사 겹치는 크기
        for (int last = 0; last < k; last++)
            for (int next = 0; next < k; next++) {
                if (last == next) {
                    overlap[last][next] = 0;
                    continue;
                }
                overlap[last][next] = d(word[last], word[next]);
            }
    }
    void calc(void) {
        ans = reconstruct(k, 0);
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
    cin.tie(NULL);

    int C; cin >> C;
    Restore r;
    while (C--)
        r.solve();

    return 0;
}