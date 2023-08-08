//1707 이분 그래프
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int k, v, e;
int vis[20001];
vector <int>vec[20001];

void init() {
	for (int i = 1;i <= v;i++)vis[i] = 0;
    for (int i = 0;i <= v;i++)vec[i].clear();
}

void bfs(int st) {
	queue <int> q;
	q.push(st);
	int color = 1;//RED
	vis[st] = 1;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if (vis[now] == 1)color = 2;
		else color = 1;

		int siz = vec[now].size();
		for (int i = 0;i < siz;i++) {
			int next = vec[now][i];
			if (!vis[next]) {
				vis[next] = color;
				q.push(next);
			}
		}
	}

}

void dfs(int st) {
	if (!vis[st]) {
		vis[st] = 1;	//	RED
	}
	int siz = vec[st].size();
	for (int i = 0;i < siz;i++) {
		int n = vec[st][i];
		if (!vis[n]) {
			if (vis[st] == 1)vis[n] = 2;
			else vis[n] = 1;
			dfs(n);
		}
		
	}
}

bool isbp() {
	for (int i = 1; i <= v; i++) {
		int siz = vec[i].size();
		for (int j = 0; j < siz; j++) {
			int next = vec[i][j];
			if (vis[i] == vis[next]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	cin >> k;
	while (k--) {
		cin >> v >> e;
		for (int i = 0;i < e;i++) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		
		for (int i = 1;i <= v;i++) {
			if (!vis[i]) {
				//bfs(i);
				dfs(i);
			}
		}
		if (isbp()) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
		init();
	}

}