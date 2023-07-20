//1504 특정한 최단 경로 
// 다익스트라 알고리즘

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
#define MAX 810

using namespace std;
int n, m;
int v1, v2;
int mapp[MAX], vis[MAX];
vector <pair<int, int>> v[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> root;

void init() {
	for (int i = 1; i <= n; i++)mapp[i] = INF;
	//for (int i = 1; i <= n; i++)vis[i] = 0;
}

void dijk() {
	while (!root.empty()) {
		int r = root.top().first;
		int d = root.top().second;
		root.pop();
		for (int k = 0; k < v[r].size(); k++) {
			int n = v[r][k].first;
			int nd = v[r][k].second;

			if (mapp[n] > nd + d) {
				mapp[n] = nd + d;
				root.push({ n,d + nd });
			}
		}
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
	init();
	root.push({ 1,0 });
	mapp[1] = 0;
	dijk();
	int stov1 = mapp[v1];
	int stov2 = mapp[v2];
	init();
	root.push({ v1,0 });
	mapp[v1] = 0;
	dijk();
	int v1tov2 = mapp[v2];
	int edtov1 = mapp[n];
	init();
	root.push({ v2,0 });
	mapp[v2] = 0;
	dijk();
	int edtov2 = mapp[n];
	
	int anss = INF;
	anss = min(anss, stov2 + v1tov2 + edtov1);
	anss = min(anss, stov1 + v1tov2 + edtov2);
	if (v1tov2 == INF || anss == INF)cout << -1;
	else cout << anss << endl;



}