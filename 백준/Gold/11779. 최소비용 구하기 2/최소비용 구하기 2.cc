//11779 최소비용 구하기 2 - re-
// route 저장하는 아이디어 위주로

#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define INF 987654321

using namespace std;
int n, m, st, ed;
int arr[1001];
int r[1001];
vector<pair<int, int>> ver[1001];
vector<int>route;

void dijk(){
	priority_queue<pair<int, int>> pq;// cost, city

	pq.push({ 0,st });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int city = pq.top().second;
		pq.pop();
        if (cost > arr[city])continue;

		for (int i = 0;i < ver[city].size();i++) {
			int n = ver[city][i].first;
			int nc = ver[city][i].second;

			if (arr[n] > cost + nc) {
				r[n] = city;
				//cout << city <<" : " << n << endl;
				arr[n] = cost + nc;
				pq.push({ -arr[n], n });
			}
		}
	}
	int t = ed;
	while (t) {
		route.push_back(t);
		t = r[t];
	}
	cout << arr[ed] << endl;
	cout << route.size() << endl;
	for (int i = route.size() - 1;i >= 0;i--) {
		cout << route[i] << " ";
	}
	cout << endl;
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++)arr[i] = INF;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		ver[a].push_back({ b,c });
	}
	cin >> st >> ed;
	arr[st] = 0;
	dijk();

}