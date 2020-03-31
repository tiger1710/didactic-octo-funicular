#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#define endl '\n'
using namespace std;

class LIS {
private:
    int n, m, ans;
    vector<int> sequence[2], cache[2], optimize[2];

    int length(const int& indexA, const int& indexB) {

    }
    

    void input(void) {
        cin >> n >> m;
        sequence[0] = cache[0] = vector<int>(n);//A
        sequence[1] = cache[1] = vector<int>(m);//B
        optimize[0].clear(); optimize[0].push_back(numeric_limits<int>::max());//A
        optimize[1].clear(); optimize[1].push_back(numeric_limits<int>::max());//B
        for (auto& r : sequence)
            for (int& c : r)
                cin >> c;
        
    }
    void calc(void) {
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
    cin.tie(nullptr);

    int C; cin >> C;
    LIS lis;
    for (int testCase = 0; testCase < C; testCase++) {
        lis.solve();
    }
    
    return 0;
}