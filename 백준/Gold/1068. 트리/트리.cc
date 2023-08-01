//1068 트리

#include <iostream>
#include <vector>

using namespace std;
int n, del, cntt, root;
vector <int>v[51];

void dfs(int r) {
	if (r == del)return;
	int s = v[r].size();
	if (s == 0) {
		cntt++;
		return;
	}
	for (int i = 0;i < s;i++) {
		int k = v[r][i];
		if (k == del) {
			if (s == 1)cntt++;
			continue;
		}
		dfs(k);
	}
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		if (a == -1) {
			root = i;
			continue;
		}
		v[a].push_back(i);
	}
	cin >> del;
	dfs(root);
	cout << cntt << endl;
}