#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class SqureMatrix {
private:
    vector<vector<double>> mat;
    int n;
    vector<vector<double>> multiplication(const vector<vector<double>>& A, const vector<vector<double>>& B) {
        const int n = A.size();

        vector<vector<double>> C(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; i++)
            for (int r = 0; r < n; r++)
                for (int c = 0; c < n; c++)
                    C[i][r] += A[i][c] * B[c][r];

        return C;
    }
public:
    vector<double>& operator[](const unsigned int& p) {
        return mat[p];
    }
    vector<vector<double>> pow(const int& n) {
        if (n == 1) return mat;
        vector<vector<double>> squred = pow(n / 2);
        if (n & 1) return multiplication(multiplication(squred, squred), mat);
        else return multiplication(squred, squred);
    }
    SqureMatrix(const vector<vector<double>>& v) {
        this->mat = v;
    }
    
    SqureMatrix(const int& n) {
        int size = static_cast<int>(sqrt(n));
        this->mat = vector<vector<double>>(n, vector<double>(n));
    }
};

class Genius {
private:
    int N, K, M;//곡의 수, K분 후, 좋아하는 곡
    vector<int> L;
    vector<vector<double>> T;

    //cache[time][song] = time분 후에 song번 노래가 시작할 확률.
    vector<double> getProb1(void) {
        vector<vector<double>> cache(5, vector<double>(N, 0));
        cache[0][0] = 1.0;
        for (int time = 1; time <= K; time++)
            for (int song = 0; song < N; song++) {
                double& prob = cache[time % 5][song];
                prob = 0.0;
                for (int last = 0; last < N; last++)
                    prob += cache[(time - L[last] + 5) % 5][last] * T[last][song];
            }

        vector<double> ret(N);
        for (int song = 0; song < N; song++)
            for (int start = K - L[song] + 1; start <= K; start++)
                ret[song] += cache[start % 5][song];

        return ret;
    }
    vector<double> getProb2(void) {
        SqureMatrix W(N << 2);
        for (int i = 0; i < 3 * N; i++)
            W[i][i + N] = 1.0;

        for (int i = 0; i < N; i++)
            for (int k = 0; k < N; k++)
                W[3 * N][(4 - L[i]) * N + k] = T[k][i];
        
        SqureMatrix Wk = W.pow(K);
        vector<double> ret(N);
        for (int song = 0; song < N; song++)
            for (int start = 0; start < L[song]; start++)
                ret[song] += Wk[(3 - start) * N + song][3 * N];

        return ret;
    }
public:
};

int main(void) {
    ios_base::sync_with_stdio(false);

    return 0;
}