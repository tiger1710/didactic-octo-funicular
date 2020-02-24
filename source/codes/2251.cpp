#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

class Bottle {
private:
    int volume[3];
    int buket[3] = { 0, 0, 0 };

    void pour(int& from, int& to) {
        if (volume[to] - buket[to] >= buket[from]) {
            buket[to] += buket[from];
        }
        else {
            buket[from] -= (volume[to] - buket[to]);
            buket[to] = volume[to];
        }
    }

    void input(void) {
        for (int& i : volume) {
            cin >> i;
        }
        buket[0] = buket[1] = 0;
        buket[2] = volume[2];
    }
public:
};

class {

};

int main(void) {
    ios_base::sync_with_stdio(false);

    return 0;
}