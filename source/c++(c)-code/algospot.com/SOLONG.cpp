#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#define endl '\n'
using namespace std;

class TrieNode {
private:
	friend class SoLong;
	static const int ALPHABETS = 26;
	vector<unique_ptr<TrieNode>> children;
	int terminal;
	int first;
	
	void insert(const char* key, const int& id) {
		if (first == -1) first = id;
		
		if (*key == '\0') terminal = id;
		else {
			int next = *key - 'A';
			
			if (children[next] == nullptr)
				children[next] = unique_ptr<TrieNode>(new TrieNode);
			
			children[next]->insert(key + 1, id);
		}
	}
	const TrieNode* find(const char* key) {
		if (*key == '\0') return this;
		int next = *key - 'A';
		if (children[next] == nullptr) return nullptr;
		return children[next]->find(key + 1);
	}
	
	int type(const char* key, const int& id) {
		if (*key == '\0') return 0;
		if (first == id) return 1;
		
		int next = *key - 'A';
		return 1 + children[next]->type(key + 1, id);
	}
public:
	TrieNode(void) : children(ALPHABETS), terminal(-1), first(-1) { }
	
	int countKeys(const string& word) {
		const TrieNode* node = find(&word[0]);
		if (node == nullptr or node->terminal == -1) return word.length();
		return type(&word[0], node->terminal);
	}
};
class SoLong {
private:
	int N, M, ans;
	vector<pair<int, string>> dictionary;
	unique_ptr<TrieNode> trie;
	
	void init(void) {
		sort(dictionary.begin(), dictionary.end());
		trie = unique_ptr<TrieNode>(new TrieNode);
		for (int i = 0; i < N; i++)
			trie->insert(dictionary[i].second.c_str(), i);
		trie->first = -1;
		ans = M - 1;
	}
	
	void input(void) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			string buf; int freq;
			cin >> buf >> freq;
			dictionary.push_back(make_pair(-freq, buf));
		}
	}
	void calc(void) {
		init();
		while (M--) {
			string str; cin >> str;
			ans += trie->countKeys(str);
		}
	}
	void output(void) {
		cout << ans << endl;
		dictionary.clear();
		trie.reset();
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
	SoLong sl;
	while (C--)
		sl.solve();
	
	return 0;
}