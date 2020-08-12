#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define endl '\n'
using namespace std;

class Zimbabwe {
private:
    const int MOD = 1000000007;
    string e, digits;
    int n, m;
    vector<vector<vector<int>>> cache;
    int ans;

    //index:�̹��� ä�� �ڸ��� �ε���
    //taken:���ݱ��� ����� �ڸ������� ����
    //mod:���ݱ��� ���� ������ m�� ���� ������
    //less:���ݱ��� ���� ������ �̹� e���� ������ 1, �ƴϸ� 0
    int price(const int& index, const int& taken, const int& mod, const int& less) {
        if (index == n) return (less and mod == 0) ? 1 : 0;

        int& ret = cache[taken][mod][less];
        if (ret not_eq -1) return ret;

        ret = 0;
        for (int next = 0; next < n; next++)
            if ((taken bitand (1 << next)) == 0) {
                if (not less and e[index] < digits[next]) continue;

                if (next > 0 and digits[next - 1] == digits[next] and 
                    (taken bitand (1 << (next - 1))) == 0) continue;
                
                int nextTaken = taken bitor (1 << next);
                int nextMod = (mod * 10 + digits[next] - '0') % m;
                int nextLess = less or e[index] > digits[next];
                ret += price(index + 1, nextTaken, nextMod, nextLess);
                ret %= MOD;
            }
        return ret;
    }


    void input(void) {
        cin >> e >> m;
        digits = e; n = e.length();
        sort(digits.begin(), digits.end());
        cache = vector<vector<vector<int>>>(1 << 14, vector<vector<int>>(m, vector<int>(2, -1)));
    }
    void calc(void) {
        ans = price(0, 0, 0, 0);
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

    int c; cin >> c;
    Zimbabwe z;
    while (c--)
        z.solve();


    return 0;
}