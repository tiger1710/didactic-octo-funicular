#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

class Traversal {
private:
    int N;
    vector<int> preorder, inorder;

    void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
        if (preorder.empty()) return;

        const int root = preorder.front();

        const int size = find(inorder.begin(), inorder.end(), root) - inorder.begin();

        printPostOrder(vector<int>(preorder.begin() + 1, preorder.begin() + size + 1),
                    vector<int>(inorder.begin(), inorder.begin() + size));
        printPostOrder(vector<int>(preorder.begin() + size + 1, preorder.end()),
                    vector<int>(inorder.begin() + size + 1, inorder.end()));

        cout << root << ' ';
    }

    void input(void) {
        cin >> N;
        preorder = inorder = vector<int>(N);
        for (int& i : preorder) cin >> i;
        for (int& i : inorder) cin >> i;
    }
    void calc(void) { printPostOrder(preorder, inorder); }
    void output(void) { cout << endl; }
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
    Traversal travel;
    while (C--) travel.solve();

    return 0;
}