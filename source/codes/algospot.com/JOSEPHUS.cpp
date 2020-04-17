#include <iostream>
#include <list>
#define endl '\n'
using namespace std;

class Josephus {
private:
    int N, K;
    list<int> survivors;

    void input(void) {
        cin >> N >> K;
        for (int i = 0; i < N; i++)
            survivors.push_back(i + 1);
    }
    void calc(void) {
        list<int>::iterator kill = survivors.begin();

        while (survivors.size() > 2) {
            kill = survivors.erase(kill);
            if (kill == survivors.end()) kill = survivors.begin();

            for (int i = 0; i < K - 1; i++) {
                kill++;
                if (kill == survivors.end()) kill = survivors.begin();
            }
        }

    }
    void output(void) {
        for (int& i : survivors) cout << i << ' ';
        cout << endl;
        survivors.clear();
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
    Josephus joseph;
    while (C--)
        joseph.solve();




    return 0;
}