#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

class RNG {
private:
    int seed;
    const int a, b;
    void setSeed(const int& seed) {
        this->seed = seed;
    }
public:
    RNG(const int& a, const int& b) : a(a), b(b), seed(1983) { }
    int next(void) {
        int ret = seed;
        setSeed(((seed * (long long)a) + b) % 20090711);
        return ret;
    }
};

class RunningMedian {
private:
    int N, a, b;
    int ans;

    int runningMedian(const int& N, RNG rng) {
        priority_queue<int, vector<int>, less<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int ret = 0;

        for (int cnt = 0; cnt < N; cnt++) {
            if (maxHeap.size() == minHeap.size()) maxHeap.push(rng.next());
            else minHeap.push(rng.next());

            if (not minHeap.empty() and not maxHeap.empty() and
                minHeap.top() < maxHeap.top()) {
                
                int maxTop = maxHeap.top(), minTop = minHeap.top();
                maxHeap.pop(); minHeap.pop();
                maxHeap.push(minTop);
                minHeap.push(maxTop);
            }
            ret = (ret + maxHeap.top()) % 20090711;
        }
        return ret;
    }

    void input(void) {
        cin >> N >> a >> b;
    }
    void calc(void) {
        ans = runningMedian(N, RNG(a, b));
    }
    void output(void) {
        cout << ans << endl;
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
    RunningMedian rm;
    while (C--)
        rm.solve();


    return 0;
}