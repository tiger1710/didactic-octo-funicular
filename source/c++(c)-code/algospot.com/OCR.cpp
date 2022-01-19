#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;

class OCR {
private:
    int m, q, n;//m:���� �ܾ��, q:query, n ��ȯ����ܾ��
    vector<string> corpus;//�ܾ��
    vector<vector<double>> T, M, cache;//T:i�ܾ� ������ k�ܾ��� Ȯ��. / M:i�ܾ k�ܾ�� �з��� Ȯ��.
    vector<double> B;
    vector<int> R;//�з��Ⱑ ��ȯ�� ����. ��ȣ�� ��ȯ.
    vector<vector<int>> choice;

    string ans;


    double recognize(const int& segment, const int& previousMatch) {
        if (segment == n) return 0.0;
        double& ret = cache[segment][previousMatch];
        if (ret not_eq 1.0) return ret;
        ret = -1e200;//log(0) == -INF
        int& choose = choice[segment][previousMatch];

        for (int thisMatch = 1; thisMatch <= m; thisMatch++) {
            //logA + logB = logAB (Ȯ���� ��), previousMatch = 0 �̸� ù���� Ȯ��(B).
            double cand = T[previousMatch][thisMatch]//previousMatch�ܾ� ������ thisMatch�ܾ��� Ȯ��
                            + M[thisMatch][R[segment]]//thisMatch�ܾ R[segment]�ܾ�� �з��� Ȯ��
                            + recognize(segment + 1, thisMatch);

            if (ret < cand) {
                ret = cand;
                choose = thisMatch;
            }
        }
        return ret;
    }
    string reconstruct(const int& segment, const int& previousMatch) {
        int choose = choice[segment][previousMatch];
        string ret = corpus[choose - 1];
        if (segment < n - 1)
            ret = ret + " " + reconstruct(segment + 1, choose);
        return ret;
    }
    void init() {
        cin >> n;
        R = vector<int>(n);
        for (int words = 0; words < n; words++) {
            string str; cin >> str;
            R[words] = find(corpus.begin(), corpus.end(), str) - corpus.begin() + 1;
        }
        //log1 = 0
        cache = vector<vector<double>>(n + 1, vector<double>(1 + m, 1.0));
        choice = vector<vector<int>>(n + 1, vector<int>(1 + m));
    }

    void input(void) {
        cin >> m >> q;

        corpus = vector<string>(m);
        for (string& i : corpus) cin >> i;
        
        B = vector<double>(m);
        T = vector<vector<double>>(m + 1, vector<double>(m + 1));
        M = vector<vector<double>>(m + 1, vector<double>(m + 1));

        for (int c = 1; c <= m; c++) {
            cin >> T[0][c];
            T[0][c] = log(T[0][c]);
        }

        for (int r = 1; r <= m; r++)
            for(int c = 1; c <= m; c++) {
                cin >> T[r][c];
                T[r][c] = log(T[r][c]);
            }

        for (int r = 1; r <= m; r++)
            for(int c = 1; c <= m; c++) {
                cin >> M[r][c];
                M[r][c] = log(M[r][c]);
            }
    }
    void calc(void) {
        while (q--) {
            init();
            double val = recognize(0, 0);
            ans = reconstruct(0, 0);
            output();
        }
    }
    void output(void) {
        cout << ans << endl;
    }
public:
    void solve(void) {
        input();
        calc();
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    OCR().solve();

    return 0;
}