#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#define endl '\n'
using namespace std;
int L, R, C;

class Point {
private:
public:
    int l, r, c;
    Point() { }
    Point(const int& l, const int& r, const int& c) {
        this->l = l, this->r = r, this->c = c;
    }
    void set(const int& l, const int& r, const int& c) {
        this->l = l, this->r = r, this->c = c;
    }
    Point operator+(const Point& p) {
        return Point(this->l + p.l, this->r + p.r, this->c + p.c);
    }
};

void input(vector<vector<vector<char>>>& building, Point p[2], const int& L, const int& R, const int& C) {
    cin.ignore();
    for (int l = 0; l < L; l++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                c = cin.get();
                switch (c) {
                case 'S':
                    p[0].set(l, r, c);
                    break;
                case 'E':
                    p[1].set(l, r, c);
                    break;
                default:
                    break;
                }
            }
            cin.ignore();
        }
        cin.ignore();
    }
}

int& visited(vector<vector<vector<int>>>& visit, const Point& p) {
    return visit[p.l][p.r][p.c];
}

bool isSafe(const Point& p) {
    return 0 <= p.l and p.l < L and 0 <= p.r and p.r < R and 0 <= p.c and p.c < C;
}

void bfs(vector<vector<vector<char>>>& building, Point& start, Point& end) {
    static Point diff[6] = { Point(0, -1, 0), Point(0, 1, 0), Point(0, 0, -1),
                            Point(0, 0, 1), Point(-1, 0, 0), Point(1, 0, 0) };

    vector<vector<vector<int>>> visit(L, vector<vector<int>>(R, vector<int>(C, 0)));
    queue<Point> q;
    q.push(start);
    visited(visit, start);

    while (not q.empty()) {
        Point cur = q.front(); q.pop();

        for (Point& d : diff) {
            Point next = cur + d;

            if (isSafe(next) and not visited(visit, next)) {
                visited(visit, next) = visited(visit, cur) + 1;
                q.push(next);
            }
        }

        q.pop();
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false);

    while (true) {
        cin >> L >> R >> C;
        if (L == 0 and R == 0 and C == 0) break;

        vector<vector<vector<char>>> building(L, vector<vector<char>>(R, vector<char>(C)));
        Point p[2]; //start, end
        input(building, p, L, R, C);

        

        
    }

    return 0;
}