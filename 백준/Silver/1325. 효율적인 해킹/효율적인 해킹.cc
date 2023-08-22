//1325 효율적인 해킹

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, cntt, mxx;
int vis[10001], cp[10001];
vector <int> v[10001];

void init() {
	for (int i = 1; i <= n; i++)vis[i] = 0;
}

void bfs(int st) {
	queue <int>q;
	vis[st] = 1;
	cntt++;
	q.push(st);
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 0; i < v[k].size(); i++) {
			if (vis[v[k][i]] == 0) {
				vis[v[k][i]] = 1;
				cntt++;
				q.push(v[k][i]);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		init();
		bfs(i);
		if (mxx < cntt)mxx = cntt;
		cp[i] = cntt;
		cntt = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (cp[i] == mxx)cout << i << " ";
	}
	cout << endl;
}