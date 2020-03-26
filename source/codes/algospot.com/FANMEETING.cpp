#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

class Fanmeeting {
private:
    string member;
    string fan;
    int ans;

    void addTo(vector<int>& a, vector<int>& b, const int& k) {
        for (int i = 0; i < k; i++) b.insert(b.begin(), k, 0);
        if (a.size() < b.size()) swap(a, b);
        for (int i = 0; i < b.size(); i++) a[i] += b[i];
    }
    void subFrom(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < b.size(); i++) {
            a[i] -= b[i];
        }
        while (a.back() == 0) a.pop_back();
    }
    vector<int> multiply(vector<int>& a, vector<int>& b) {
        vector<int> c(a.size() + b.size());
        for (int i = 0; i < a.size(); i++) {
            for (int k = 0; k < b.size(); k++)
                c[i + k] += a[i] * b[k];
        }
        while(c.back() == 0) c.pop_back();
        return c;
    }
    vector<int> karatsuba(vector<int>& fan, vector<int>& member) {
        int a_n = fan.size(), b_n = member.size();
        if (a_n == 0 or b_n == 0) return vector<int>();
        if (a_n < b_n) return karatsuba(member, fan);
        if (a_n < 5) return multiply(fan, member);

        int half = a_n >> 1;

        vector<int> a_0(fan.begin(), fan.begin() + half), a_1(fan.begin() + half, fan.end());
        vector<int> b_0(member.begin(), member.begin() + min(b_n, half)), b_1(member.begin() + min(b_n, half), member.end());

        vector<int> z_2 = karatsuba(a_1, b_1), z_0 = karatsuba(a_0, b_0);

        addTo(a_0, a_1, 0); addTo(b_0, b_1, 0);

        vector<int> z_1(karatsuba(a_0, b_0));
        subFrom(z_1, z_0); subFrom(z_1, z_2);

        vector<int> ret;
        addTo(ret, z_0, 0);
        addTo(ret, z_1, half);
        addTo(ret, z_2, half << 1);
        return ret;
    }
    void hug(void) {
        reverse(member.begin(), member.end());
        vector<int> FAN(fan.begin(), fan.end()), MEMBER(member.begin(), member.end());
        vector<int> ret = karatsuba(FAN, MEMBER);
        
    }

    void input(void) {
        cin >> member >> fan;
        for (char& ch : member) ch -= 'F';
        for (char& ch : fan) ch -= 'F';
        ans = 0;
    }
    void calc(void) {
        hug();
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
    Fanmeeting fm;
    for (int testCase = 0; testCase < C; testCase++) {
        fm.solve();
    }


    return 0;
}