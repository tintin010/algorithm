// 18352 특정 거리의 도시 찾기
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, k, x;
int visit[300001];
int d[300001];
vector <int> v[300001];

void di(int a) {
	d[a] = 0;
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (d[next] > d[cur] + 1) {
				d[next] = d[cur] + 1;
				q.push(next);
			}
		}
	}

}


int main() {
	cin >> n >> m >> k >> x;
	for (int i = 1; i <= n; i++) d[i] = 987654321;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	di(x);

	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			flag = 1;
			cout << i << endl;
		}
	}
	if (!flag)cout << "-1";
} 