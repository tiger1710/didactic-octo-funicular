#include <iostream>
#include <string>
#include <stack>
#define endl '\n'
using namespace std;

class Brackets2 {
private:
    string formula;
    bool ans;

    void input(void) { cin >> formula; }
    bool calc(void) {
        const string opening("({["), closing(")}]");
        
        stack<char> openStack;
        for (const char& ch : formula) {
            if (opening.find(ch) not_eq string::npos) openStack.push(ch);
            else {
                if (openStack.empty()) return false;
                if (opening.find(openStack.top()) not_eq closing.find(ch))
                    return false;
                openStack.pop();
            }
        }

        return openStack.empty();
    }
    void output(void) { cout << (ans ? "YES" : "NO") << endl; }
public:
    void solve(void) {
        input();
        ans = calc();
        output();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C; cin >> C;
    Brackets2 brackets;
    while (C--) brackets.solve();

    return 0;
}