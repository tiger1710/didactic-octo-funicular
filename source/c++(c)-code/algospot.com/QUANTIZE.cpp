#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define endl '\n'
using namespace std;

class Quantization {
private:
    const int INF = 987654321;
    int N, S, ans;
    vector<int> sequence, partialSum, partialSquareSum;
    vector<vector<int>> cache;

    int var(const int& from, const int& to) {
        const int sum = partialSum[to] - partialSum[from];
        const int squareSum = partialSquareSum[to] - partialSquareSum[from];

        int mean = static_cast<int>(0.5 + static_cast<double>(sum) / (to - from));

        return squareSum - ((mean * sum) << 1) + mean * mean * (to - from);
    }
    int quantize(const int& from, const int& part) {
        if (from == N) return 0;
        if (part == S) return INF;

        int& ret = cache[from][part];
        if (ret not_eq -1) return ret;
        ret = INF;

        for (int partSize = 1; from + partSize <= N; partSize++) {
            ret = min(ret, quantize(from + partSize, part + 1) + var(from, from + partSize));
        }
        return ret;
    }
    void input(void) {
        cin >> N >> S;
        sequence = vector<int>(N);
        for (int& i : sequence) cin >> i;
        sort(sequence.begin(), sequence.end());

        cache = vector<vector<int>>(N, vector<int>(S, -1));
        partialSum = partialSquareSum = vector<int>(1);
        for (int i = 0; i < N; i++) {
            partialSum.push_back(partialSum[i] + sequence[i]);
            partialSquareSum.push_back(partialSquareSum[i] + sequence[i] * sequence[i]);
        }
    }
    void calc(void) {
        ans = quantize(0, 0);
        ans = N == 1 ? 0 : ans;
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
    
    Quantization q;
    while (C--) {
        q.solve();
    }

    return 0;
}