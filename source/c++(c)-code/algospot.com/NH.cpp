#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#define endl '\n'
using namespace std;

const int ALPHABETS = 26;
class TrieNode {
private:
	friend class NH;
	int terminal, no;
	shared_ptr<TrieNode> fail;
	vector<shared_ptr<TrieNode>> children, next;
	vector<int> output;
	
	void insert(const char* key, const int& id) {
		if (*key == '\0') {
			terminal = id;
			return;
		}
		int next = *key - 'a';//***'A' 가 아니였다...
		if (children[next] == nullptr) {
			//cout << "key:" << *key << " was inserted!!!" << endl;
			children[next] = shared_ptr<TrieNode>(new TrieNode);
			//if (children[next])
			//	cout << "children[" << next << "] memory allocated!!!" << endl;
		}
		children[next]->insert(key + 1, id);
	}
public:
	TrieNode(void) : children(ALPHABETS), next(ALPHABETS), terminal(-1), no(-1) { }
};

class NH {
private:
	const int MOD = 10007;
	int nodeCounter;
	int N, M, ans;
	vector<vector<int>> cache;
	shared_ptr<TrieNode> root;
	
	void computeFailFunc(void) {
		queue<shared_ptr<TrieNode>> q;
		root->fail = root;
		q.push(root);
		while (not q.empty()) {
			shared_ptr<TrieNode> here = q.front(); q.pop();
			
			for (int edge = 0; edge < ALPHABETS; edge++) {
				shared_ptr<TrieNode> child = here->children[edge];
				if (child == nullptr) continue;
				
				if (here == root) child->fail = root;
				else {
					shared_ptr<TrieNode> parent = here->fail;
					while (parent not_eq root and parent->children[edge] == nullptr)
						parent = parent->fail;
					
					if (parent->children[edge])
						parent = parent->children[edge];
					child->fail = parent;
				}
				
				child->output = child->fail->output;
				if (child->terminal not_eq -1)
					child->output.push_back(child->terminal);
				q.push(child);
			}
		}
	}
	
	int count(const int& length, const shared_ptr<TrieNode>& state) {
		if (state->output.size()) return 0;
		if (length == 0) return 1;
		int& ret = cache[length][state->no];
		if (ret not_eq -1) return ret;
		
		ret = 0;
		for (int letter = 0; letter < ALPHABETS; letter++) {
			ret += count(length - 1, state->next[letter]);
			ret %= MOD;
		}
		return ret;
	}
	void computeTransition(const shared_ptr<TrieNode>& here) {
		here->no = nodeCounter++;
		for (int chr = 0; chr < ALPHABETS; chr++) {
			shared_ptr<TrieNode> next = here;
			while (next not_eq next->fail and next->children[chr] == nullptr)
				next = next->fail;
			if (next->children[chr]) next = next->children[chr];
			here->next[chr] = next;
			
			if (here->children[chr]) {
				//cout << static_cast<char>('a' + chr) << endl;
				computeTransition(here->children[chr]);
			}
		}
	}
	
	void input(void) {
		cin >> N >> M;
		root = shared_ptr<TrieNode>(new TrieNode);
		for (int id = 0; id < M; id++) {
			string str; cin >> str;
			root->insert(&str[0], id);
		}
		
		nodeCounter = 0;
		computeFailFunc();
		computeTransition(root);
		cache = vector<vector<int>>(N + 1, vector<int>(nodeCounter + 1, -1));
	}
	void calc(void) {
		ans = count(N, root);
	}
	void output(void) {
		cout << ans << endl;
		//for (int i = 0; i < N; i++)
		//	if (root->children[i])
		//		cout << "root->children[" << i << "] is available!!!" << endl;
		root.reset();
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
	NH nh;
	while (C--)
		nh.solve();
	
	return 0;
}