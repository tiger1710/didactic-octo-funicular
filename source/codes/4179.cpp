#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
using namespace std;
typedef pair<int, int> point;

class Fire {
private:
    int R, C;
    vector<vector<char>> maze;
    vector<vector<int>> visit;
    vector<point> jihun_and_fire;
    char& pos(const point& p) {
        return maze[p.first][p.second];
    }
    int& visited(const point& p) {
        return visit[p.first][p.second];
    }

    void input(void) {
        cin >> R >> C; cin.ignore();
        maze = vector<vector<char>>(R, vector<char>(C));
        for (auto& row : maze) {
            for (auto& col : row) {
                cin >> col;
                switch (col) {
                    case 'J':
                    case 'F':
                    jihun_and_fire.push_back(point(&row - &maze[0], &col - &row[0]));
                    break;
                    default:
                    break;
                }
            }
        }
    }

    void calc(void) {
        queue<point> q;
        q.push(J); visited(J) = 1;
        for (const point& F : fire) {
            q.push(F);
        }
    }

public:

};

int main(void) {
    ios_base::sync_with_stdio(false);

    Fire jihun_want_escape;

    return 0;
}