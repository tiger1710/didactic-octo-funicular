#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class SqureMatrix {
private:
    vector<vector<double>> mat;
    int n;
public:
    SqureMatrix(const int& n) {
        this->n = n;
        mat = vector<vector<double>>(n, vector<double>(n));
    }
    SqureMatrix pow(const int& k) {
        vector<vector<double>> ret(n, vector<double>(n));
        for (vector<double>& r : ret)
            for (double& c : r) {
                double sum = 0.0;
                for (int i = 0; i < n; i++)
                    for (int k = 0; k < n; k++)
                        sum += mat[i][k] * mat[k][i];
                c = sum;
            }
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
        
    }
public:
};

int main(void) {
    ios_base::sync_with_stdio(false);

    return 0;
}