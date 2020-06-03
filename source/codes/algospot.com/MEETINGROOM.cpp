#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
//#define endl '\n'
using namespace std;
typedef pair<int, int> Interval;

class SCC {
private:
	vector<vector<int>> adj;
	vector<int> sccId, discovered;
	stack<int> st;
	int sccCounter, vertexCounter;
	
	void init() {
		sccId = discovered = vector<int>(adj.size(), -1);
		sccCounter = vertexCounter = 0;
	}
	int scc(const int& here) {
		int ret = discovered[here] = vertexCounter++;
		st.push(here);
		
		for (const int& there : adj[here])
			if (discovered[there] == -1)
				ret = min(ret, scc(there));
			else if (sccId[there] == -1)
				ret = min(ret, discovered[there]);
		
		if (ret == discovered[here]) {
			while (true) {
				int t = st.top();
				st.pop();
				sccId[t] = sccCounter;
				if (t == here) break;
			}
			sccCounter++;
		}
		
		return ret;
	}
public:
	SCC(const vector<vector<int>>& adj) : adj(adj) { }
	
	vector<int> tarjanSCC(void) {
		init();
		for (int i = 0; i < adj.size(); i++)
			if (discovered[i] == -1)
				scc(i);
		return sccId;
	}
};

class MeetingRoom {
private:
	int N;
	vector<vector<int>> adj;
	vector<Interval> meetings;
	vector<int> ans;
	
	bool disjoint(const Interval& a, const Interval& b) {
		return a.second <= b.first or b.second <= a.first;
	}
	//meetings[] -> 2-SAT 문제로
	//meetings[2i] or meetings[2i + 1] 하나 픽
	//vartex[0]:A_0, vartex[1]:!A_0, vartex[2]:A_1, vartex[3]:!A_1...
	void makeGraph(void) {
		adj = vector<vector<int>>(meetings.size() << 1);
		for (int i = 0, k; i < meetings.size(); i += 2) {
			k = i + 1;
			//2i, 2i + 1 중 하나 pick 무조건 하나만 pick 해야하므로 (2), (4) 추가
			adj[(i << 1) + 1].push_back(k << 1);//not i -> k (1)
			adj[(i << 1)].push_back((k << 1) + 1);//i -> not k; (2)
			adj[(k << 1) + 1].push_back(i << 1);//not k -> i (3)
			adj[(k << 1)].push_back((i << 1) + 1);//k -> not i; (4)
		}
		for (int i = 0; i < meetings.size(); i++)
			for (int k = 0; k < i; k++)
				//회의가 겹치면 (i -> not k) (k -> not i)
				if (not disjoint(meetings[i], meetings[k])) {
					adj[i << 1].push_back((k << 1) + 1);
					adj[k << 1].push_back((i << 1) + 1);
				}
	}
	vector<int> calc2SAT(void) {
		vector<int> label = SCC(adj).tarjanSCC();//return sccId;
		
		for (int i = 0; i < adj.size(); i += 2)
			if (label[i] == label[i + 1]) {
				return vector<int>();
			}
		
		vector<int> value(meetings.size(), -1);
		vector<Interval> order;
		for (int i = 0; i < adj.size(); i++)
			order.push_back(make_pair(-label[i], i));
		sort(order.begin(), order.end());
		
		for (int i = 0; i < adj.size(); i++) {
			int vertex = order[i].second;
			int variable = vertex >> 1;
			int isTrue = vertex % 2 == 0;
			if (value[variable] not_eq -1) continue;
			value[variable] = not isTrue;
		}
		return value;
	}
	
	void input(void) {
		cin >> N;
		meetings.clear();
		for (int i = 0; i < N; i++) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			meetings.push_back(Interval(a, b));
			meetings.push_back(Interval(c, d));
		}
	}
	void calc(void) {
		makeGraph();
		ans = calc2SAT();
	}
	void output(void) {
		if (ans.empty()) cout << "IMPOSSIBLE" << endl;
		else {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < meetings.size(); i++) {
				if (ans[i])
					cout << meetings[i].first << ' ' << meetings[i].second << endl;
			}
		}
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
	MeetingRoom mr;
	while (C--)
		mr.solve();
	
	return 0;
}