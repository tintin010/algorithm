//2468 안전 영역

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int arr[101][101];
int map[101][101];
int n, m;
int anss;
int visit[101][101];
queue <pair<int,int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cntt = 0;

void reset() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visit[i][j] = 0;
		}
	}
}

void DFS(int i,int j) {
	q.push(make_pair(i, j));
	visit[i][j] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int c = a + dy[i];
			int d = b + dx[i];
			if (c > 0 && d > 0 && c <= n && d <= n && visit[c][d] == 0 && map[c][d] >= 0) {
				visit[c][d] = 1;
				q.push(make_pair(c, d));
				
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			m = max(m, arr[i][j]);
		}
	}



	for (int k = 0; k <= m; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] <= k) {
					map[i][j] = -1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] >= 0 && visit[i][j] == 0) {
					cntt++;
					DFS(i, j);
				}
			}
		}
		anss = max(cntt, anss);
		cntt = 0;
		reset();
	}
	cout << anss << endl;

}