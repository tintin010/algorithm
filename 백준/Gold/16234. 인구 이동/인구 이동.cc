#include <iostream>
#include <queue>
#include <math.h>

using namespace std;
int arr[51][51];
int vis[51][51];
int n, l, r, cntt, flag;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue <pair<int, int>>q, temp;

void init() {
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)vis[i][j] = 0;
}

void bfs() {
	int sum = 0;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		temp.push({ a,b });
		sum += arr[a][b];
		q.pop();
		for (int i = 0;i < 4;i++) {
			int na = dx[i] + a;
			int nb = dy[i] + b;
			if (na >= n || nb >= n || na < 0 || nb < 0 || vis[na][nb])continue;
			if (abs(arr[a][b] - arr[na][nb]) >= l && abs(arr[a][b] - arr[na][nb]) <= r) {
				flag = 1;
				q.push({ na,nb });
				vis[na][nb] = 1;
			}
		}
	}
	int s = temp.size();
	int d = sum / s;

	while (!temp.empty()) {
		int a = temp.front().first;
		int b = temp.front().second;
		temp.pop();
		arr[a][b] = d;
	}
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)cin >> arr[i][j];


	while (true) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (!vis[i][j]) {
					vis[i][j] = 1;
					q.push({ i,j });
					bfs();
				}
			}
		}
		if (flag) {
			cntt++;
			flag = 0;
			init();
		}
		else break;
	}

	cout << cntt;
}