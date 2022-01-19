#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

class PI {
private:
    string num;
    vector<int> cache;
    int ans;

    bool isProgressive(const string& str) {
        const int diff = str[1] - str[0];

        for (int i = 0; i < str.size() - 1; i++)
            if (str[i + 1] - str[i] not_eq diff)
                return false;

        return true;
    }
    bool isAlternating(const string& str) {
        for (int i = 0; i < str.size(); i++)
            if (str[i] not_eq str[i % 2])
                return false;

        return true;
    }

    int classify(const int& from, const int& to) {
        string str(num.substr(from, to - from));
        
        //11111
        if (str == string(str.size(), str[0])) return 1;

        //12345 54321
        bool progressive = isProgressive(str);
        if (progressive and abs(str[1] - str[0]) == 1) return 2;

        //12121
        if (isAlternating(str)) return 4;
        
        //13579 97531
        if (progressive) return 5;

        //the others
        return 10;
    }

    int memorize(const int& start) {
        if (start == num.size()) return 0;

        int& ret = cache[start];
        if (ret) return ret;

        ret = 987654321;
        for (int length = 3; length <= 5; length++)
            if (start + length <= num.size())
                ret = min(ret, memorize(start + length) + classify(start, start + length));

        return ret;
    }

    void input(void) {
        cin >> num;
        cache = vector<int>(num.size());
    }
    void calc(void) {
        ans = memorize(0);
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
    PI pi;
    while (C--) {
        pi.solve();
    }


    return 0;
}