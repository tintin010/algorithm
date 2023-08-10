//11657 타임머신

#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int n, m;
long long dis[501];
vector <pair <pair<int, int>, int>> v;

void check() {
	//cout << "CHECK" << endl;
	for (int j = 0; j < v.size(); j++) {
		//cout << "J : " << j << endl;
		int from = v[j].first.first;
		int to = v[j].first.second;
		int co = v[j].second;
		if (dis[from] == INF)continue;
		if (dis[to] > dis[from] + co) {
			//cout << "J : " << j << endl;
			cout << -1 << endl;
			return;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dis[i] == INF) cout << -1 << endl;
		else cout << dis[i] << endl;
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ {a,b},c });
		//v.push_back({ {b,a},c });
	}
	for (int i = 0; i <= n; i++)dis[i] = INF;

	dis[1] = 0;	//1번 도시에서 출발
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < v.size(); j++) {
			int from = v[j].first.first;
			int to = v[j].first.second;
			int co = v[j].second;
			if (dis[from] == INF)continue;
			if (dis[to] > dis[from] + co)dis[to] = dis[from] + co;
		}
	}
	check();

}