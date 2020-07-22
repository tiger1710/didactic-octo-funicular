#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

class OCR {
private:
    int m, q, n;//m:���� �ܾ��, q:query, n ��ȯ����ܾ��
    vector<string> corpus;//�ܾ��
    vector<vector<double>> T, M, cache;//T:i�ܾ� ������ k�ܾ��� Ȯ��. / M:i�ܾ k�ܾ�� �з��� Ȯ��.
    vector<double> B;//ù�ܾ�� ������ Ȯ��.
    vector<int> R;//�з��Ⱑ ��ȯ�� ����. ��ȣ�� ��ȯ.
    vector<vector<int>> choice;


    double recognize(const int& segment, const int& previousMatch) {
        if (segment == n) return 0.0;
        double& ret = cache[segment][previousMatch];
        if (ret not_eq 1.0) return ret;
        ret = -1e200;//log(0) == -INF
        int& choose = choice[segment][previousMatch];

        for (int thisMatch = 0; thisMatch < m; thisMatch++) {
            //logA + logB = logAB (Ȯ���� ��)
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
        string ret = corpus[choose];
        if (segment < n - 1)
            ret = ret + " " + reconstruct(segment + 1, choose);
        return ret;
    }
    void init() {
        cin >> n;
        for (int words = 0; words < n; words++) {
            string str; cin >> str;
            R[words] = find(corpus.begin(), corpus.end(), str) - corpus.begin();
        }
    }

    void input(void) {
        cin >> m >> q;

        corpus = vector<string>(m);
        for (string& i : corpus) cin >> i;
        
        B = vector<double>(m);
        for (double& i : B) cin >> i;

        T = M = vector<vector<double>>(m, vector<double>(m));
        //log1 = 0
        cache = vector<vector<double>>(m, vector<double>(m, 1.0));

        for (vector<double>& r : T)
            for (double& c : r)
                cin >> c;
        for (vector<double>& r : M)
            for (double& c : r)
                cin >> c;
    }
    void calc(void) {
        init();
        double val = recognize(0, 0);
    }
public:
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}