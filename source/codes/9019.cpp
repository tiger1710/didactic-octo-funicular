#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
using namespace std;
typedef pair<int, string> point;

class DSLR {
private:
    int start;
    int target;
    vector<string> visited;

    string (DSLR::*fpStr[4])(const string& cur) = { &DSLR::D, &DSLR::S, &DSLR::L, &DSLR::R };
    int (DSLR::*fpInt[4])(const int& cur) = { &DSLR::D, &DSLR::S, &DSLR::L, &DSLR::R };

    int D(const int& cur) {
        return ((cur << 1) % 10000);
    }
    int S(const int& cur) {
        return (cur - 1) < 0 ? 9999 : (cur - 1);
    }
    int L(const int& cur) {
        int carry = cur / 1000;
        return (cur % 1000) * 10 + carry;
    }
    int R(const int& cur) {
        int borrow = cur % 10;
        return (cur / 10) + borrow * 1000;
    }

    string D(const string& cur) {
        return cur + "D";
    }
    string S(const string& cur) {
        return cur + "S";
    }
    string L(const string& cur) {
        return cur + "L";
    }
    string R(const string& cur) {
        return cur + "R";
    }

    void input(void) {
        cin >> start >> target;
        visited = vector<string>(10000, "");
    }
    void calc(void) {
        queue<int> q;//point 형식의 자료를 넣고빼면서 연산하니 시간초과...
        q.push(start);
        visited[start] = "\r";//방문체크를 string으로 함..

        while (not q.empty()) {
            int cur(q.front()); q.pop();
            if (cur == target) break;

            for (int i = 0; i < 4; i++) {
                int next((this->*fpInt[i])(cur));
                if (visited[next] == "") {
                    visited[next] = (this->*fpStr[i])(visited[cur]);
                    q.push(next);
                }
            }
        }
    }
    void output(void) {
        cout << visited[target] << endl;
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

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        DSLR dslr;
        dslr.solve();
    }

    return 0;
}