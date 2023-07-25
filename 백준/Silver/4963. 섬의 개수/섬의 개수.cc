#include <iostream>
#include <queue>

using namespace std;
int arr[51][51];
int vis[51][51];
int w, h, cntt;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { -1,1,0,0,1,-1,1,-1 };

queue <pair<int, int>>q;

void init() {
	for (int i = 1;i <= h;i++)for (int j = 1;j <= w;j++) vis[i][j] = 0;
	while (!q.empty())q.pop();
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		//vis[x][y] = 1;
		q.pop();
		for (int i = 0;i < 8;i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx<1 || ny<1 || nx>h || ny>w || arr[nx][ny] == 0 || vis[nx][ny] == 1)continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
}

int main() {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)break;
		for (int i = 1;i <= h;i++)for (int j = 1;j <= w;j++)cin >> arr[i][j];

		for (int i = 1;i <= h;i++) {
			for (int j = 1;j <= w;j++) {
				if (vis[i][j] == 0 && arr[i][j] == 1) {
					q.push({ i,j });
					vis[i][j] = 1;
					cntt++;
					bfs();
				}
			}
		}
		cout << cntt << endl;
		cntt = 0;
		init();
		
	}
}