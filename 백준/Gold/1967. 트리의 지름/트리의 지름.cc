//1967 트리의 지름

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair<int, int>>v[10001];
int n, anss;
int vis[10001];

void dfs(int a, int len) {
	for (int i = 0;i < v[a].size();i++) {
		int n = v[a][i].first;
		int dis = v[a][i].second;
		if (vis[n])continue;
		anss = max(len + dis, anss);
		vis[n]++;
		dfs(n, len + dis);
		vis[n]--;
	}
}

int main() {
	cin >> n;
	for (int i = 1;i < n;i++) {
		int st, ed, dis;
		cin >> st >> ed >> dis;
		v[st].push_back({ ed,dis });
		v[ed].push_back({ st,dis });
	}
	for (int i = 1;i <= n;i++) {
		if (v[i].size() == 1) {
            vis[i]++;
			dfs(i, 0);
            vis[i]--;
		}
	}
	cout << anss;
}