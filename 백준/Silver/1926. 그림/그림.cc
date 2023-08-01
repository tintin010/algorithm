//1926 그림

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
int arr[501][501];
int vis[501][501];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue <pair<int, int>>q;
queue <int>pic;


void bfs() {
	int cntt = 0;
	while (!q.empty()) {
		cntt++;
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (na <= 0 || nb <= 0 || na > n || nb > m || vis[na][nb] || !arr[na][nb])continue;
			q.push({ na,nb });
			vis[na][nb] = 1;
		}
	}
	pic.push(cntt);
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++)for (int j = 1;j <= m;j++)cin >> arr[i][j];
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (!vis[i][j] && arr[i][j] == 1) {
				vis[i][j] = 1;
				q.push({ i,j });
				bfs();
			}
		}
	}
	int s = pic.size();
	int ma = 0;
	for (int i = 0;i < s;i++) {
		ma = max(ma, pic.front());
		pic.pop();
	}
	cout << s << endl;
	cout << ma << endl;
}