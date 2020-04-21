#include <iostream>
#include <vector>
#include <stack>
#define endl '\n'
using namespace std;

class Fence {
private:
    int N, ans;
    vector<int> height;

    void input(void) {
        cin >> N;
        height = vector<int>(N);
        for (int& i : height) cin >> i;
    }
    void calc(void) {//use stack
        stack<int> remaining;//남은 판자들의 위치
        height.push_back(0);
        int ret = 0;
        for (int i = 0; i < height.size(); i++) {
            while (not remaining.empty() and height[i] <= height[remaining.top()]) {
                int j = remaining.top();
                remaining.pop();
                int width = -1;

                if (remaining.empty()) width = i;
                else width = (i - remaining.top() - 1);

                ret = max(ret, height[j] * width);
            }
            remaining.push(i);
        }

        ans = ret;
    }
    void output(void) { cout << ans << endl; }
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
    Fence fence;
    while (C--) fence.solve();


    return 0;
}