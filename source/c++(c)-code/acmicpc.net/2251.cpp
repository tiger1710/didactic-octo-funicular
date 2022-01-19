#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define REP(i, from, to) for (int i = (from); i < (to); i++)

template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template<typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {
  }
};
template<typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
  }
};

int A, B, C;
vector<vector<vector<bool> > > visited;

void dfs(const int& a, const int& b, const int& c) {

}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> A >> B >> C;
    visited = vector<vector<vector<bool> > >(A, vector<vector<bool> >(B, vector<bool>(C, false)));
    visited = vec<3, bool>(A, B, C, false);


    return 0;
}
