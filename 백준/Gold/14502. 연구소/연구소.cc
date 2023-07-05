//14502 연구소

#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;
void bfs();
void wall(int);
int n, m, antt;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
int arr[9][9], tmp[9][9], visit[9][9];
//

void copy(int tmp[9][9], int a[9][9]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = a[i][j];
		}
	}
}

void wall(int c) {
	if (c == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				wall(c + 1);
				tmp[i][j] = 0;
			}
		}
	}
}

void bfs() {
	int aa[9][9];
	copy(aa, tmp);
	queue <pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (aa[i][j] == 2) q.push({ i,j });
		}
	}
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (na < 0 || na >= n || nb < 0 || nb >= m) continue;
			if (aa[na][nb] == 0) {
				aa[na][nb] = 2;
				q.push({ na, nb });
			}
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (aa[i][j] == 0) {
				count++;
			}
		}
	}
	antt = max(antt, count);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			tmp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				//copy(tmp, arr);
				tmp[i][j] = 1;
				wall(1);
				tmp[i][j] = 0;
			}
		}
	}
	cout << antt;
}