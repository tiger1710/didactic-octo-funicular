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

int& visited(vector<vector<vector<int>>>& visit, const Point& p) {
    return visit[p.l][p.r][p.c];
}

char& block(vector<vector<vector<char>>>& building, const Point& p) {
    return building[p.l][p.r][p.c];
}

bool isSafe(const Point& p) {
    return 0 <= p.l and p.l < L and 0 <= p.r and p.r < R and 0 <= p.c and p.c < C;
}

int bfs(vector<vector<vector<char>>>& building, Point& start, Point& end) {
    static Point diff[6] = { Point(0, -1, 0), Point(0, 1, 0), Point(0, 0, -1),
                            Point(0, 0, 1), Point(-1, 0, 0), Point(1, 0, 0) };

    vector<vector<vector<int>>> visit(L, vector<vector<int>>(R, vector<int>(C, 0)));
    queue<Point> q;
    q.push(start);
    visited(visit, start) = 1;;

    while (not q.empty()) {
        Point cur = q.front(); q.pop();
        if (block(building, cur) == 'E') return visited(visit, cur) - 1;

        for (Point& d : diff) {
            Point next = cur + d;

            if (isSafe(next) and (block(building, next) not_eq '#') and (not visited(visit, next))) {
                visited(visit, next) = visited(visit, cur) + 1;
                q.push(next);
            }
        }

    }
    
    return 0;
}

int input(vector<vector<vector<char>>>& building, Point p[2]) {
    cin >> L >> R >> C;
    cin.ignore();
    if (L == 0 and R == 0 and C == 0) return 1;

    building = vector<vector<vector<char>>>(L, vector<vector<char>>(R, vector<char>(C)));

    for (int l = 0; l < L; l++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                char ch = block(building, Point(l, r, c)) = cin.get();
                if (ch == 'S') p[0].set(l, r, c);
                if (ch == 'E') p[1].set(l, r, c);
            }
            cin.ignore();
        }
        cin.get();
    }
    return 0;
}

void output(vector<vector<vector<char>>>& building) {
    for (auto& l : building) {
        for (auto& r : l) {
            for (auto& c : r) {
                cout << c;
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);

    while (true) {

        vector<vector<vector<char>>> building;
        Point p[2]; //start, end
        if (input(building, p)) break;

        int minutes =  bfs(building, p[0], p[1]);

        switch (minutes) {
        case 0:
            cout << "Trapped!" << endl;
            break;
        default:
            cout << "Escaped in " << minutes << " minute(s)." << endl;
            break;
        }
        

        
    }

    return 0;
}