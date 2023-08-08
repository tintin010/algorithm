// 1167 트리의 지름

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair<int, int>>v[100001];
int n, anss, temp;
int vis[100001];

void dfs(int a, int len) {
	vis[a]++;

	if (anss < len) {
		temp = a;
		anss = len;
	}

	for (int i = 0;i < v[a].size();i++) {
		int n = v[a][i].first;
		int dis = v[a][i].second;
		if (vis[n])continue;
		//vis[n]++;
		//cout << "vis[n] : " << vis[n] << endl;
		dfs(n, len + dis);
		//vis[n]--;
	}
}

int main() {
	cin >> n;
	for (int i = 1;i < n;i++) {
		int st, ed, dis;
		cin >> st;
		while (true) {
			cin >> ed;
			if (ed == -1)break;
			cin >> dis;	
			v[st].push_back({ ed, dis });
			v[ed].push_back({ st,dis });
		}
	}
	//vis[1]++;
	dfs(1, 0);
	anss = 0;
	for (int i = 1;i <= n;i++)vis[i] = 0;
	dfs(temp, 0);

	cout << anss;
}