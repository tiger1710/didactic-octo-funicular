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
    int digit[4];
    int start;
    int target;
    bool visited[10000];

    

    void conversion(int num) {
        for (int i = 3; i >= 0; i++) {
            digit[i] = num % 10;
            num /= 10;
        }
    }
    int conversion(void) {
        return ((digit[0]*10 + digit[1])*10 + digit[2])*10 + digit[3];
    }
    void moveLeft(void) {
        int t = digit[0];
        digit[0] = digit[1]; digit[1] = digit[2]; digit[2] = digit[3];
        digit[3] = t;
    }
    void moveRight(void) {
        int t = digit[3];
        digit[3] = digit[2]; digit[2] = digit[1]; digit[1] = digit[0];
        digit[0] = t;
    }

    int D(const int& n) {
        return (n + n) % 10000;
    }
    int S(const int& n) {
        return (n - 1) < 0 ? 9999 : (n - 1);
    }
    int L(const int& n) {
        conversion(n);
        moveLeft();
        return conversion();
    }
    int R(const int& n) {
        conversion(n);
        moveRight();
        return conversion();
    }

    void input(void) {
        cin >> start >> target;
    }
    void calc(void) {
        queue<point> q;
        q.push(point(start, ""));
        visited[start] = true;

        while (not q.empty()) {
            point cur = q.front(); q.pop();

        }
    }


public:
    
};

int main(void) {
    ios_base::sync_with_stdio(false);

    return 0;
}