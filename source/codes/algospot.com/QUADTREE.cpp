#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

class QuadTree {
private:
    string ans;
    
    string reverse(string::iterator& it) {
        if (*it not_eq 'x') return string(1, *(it++));
        it++;

        string upperLeft(reverse(it));
        string upperRight(reverse(it));
        string lowerLeft(reverse(it));
        string lowerRight(reverse(it));

        return string(1, 'x') + lowerLeft + lowerRight + upperLeft + upperRight;
    }

    void input(void) {
        cin >> ans;
    }
    void calc(void) {
        string::iterator it = ans.begin();
        ans = reverse(it);
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
    QuadTree qt;
    for (int testCase = 0; testCase < C; testCase++) {
        qt.solve();
    }


    return 0;
}