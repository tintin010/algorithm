//2206 벽 부수고 이동하기 -RE-

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
int n, m;
int vis[1001][1001][2], arr[1001][1001];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs() {
	queue <pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{0,1} });
	vis[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;	//x좌표
		int y = q.front().first.second;	//y좌표
		int b = q.front().second.first;	//블럭 파괴여부
		int c = q.front().second.second;//CNT
		q.pop();
		if (x == n - 1 && y == m - 1) return c;

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;
			if (arr[nx][ny] == 1 && b == 0) {
				vis[nx][ny][b + 1] = 1;
				q.push({ {nx,ny},{b + 1,c + 1} });
			}
			if (arr[nx][ny] == 0 && vis[nx][ny][b] == 0) {
				vis[nx][ny][b] = 1;
				q.push({ {nx,ny},{b ,c + 1} });
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		string str;
		cin >> str;
		for(int j=0;j<m;j++){
			arr[i][j] = str[j] - '0';
			//cout << arr[i][j] << endl;
		}
	}
	int anss = bfs();
	cout << anss << endl;
}