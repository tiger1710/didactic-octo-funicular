#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class FENCE {
private:
    int N;
    vector<int> height;

    int ans = 0;

    int seg(const int& left, const int& right) {
        if (left == right - 1) return height[left];

        int middle = (left + right) >> 1;

        int ret = max(seg(left, middle), seg(middle, right));
        int low = middle - 1, high = middle;
        int subHeight = min(height[low], height[high]);
        ret = max(ret, subHeight << 1);

        while (left <= low or high < right) {
            if ((high < right) and (low < left or height[low] < height[high])) subHeight = min(subHeight, height[high++]);
            else subHeight = min(subHeight, height[low--]);

            ret = max(ret, (high - low - 1) * subHeight);
        }

        return ret;
    }

    void input(void) {
        cin >> N;
        height = vector<int>(N);
        for (int& h : height) cin >> h;
    }
    void calc(void) {
        ans = seg(0, N);
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
    FENCE f;
    for (int testCase = 0; testCase < C; testCase++) {
        f.solve();
    }

    return 0;
}