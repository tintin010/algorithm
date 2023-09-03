//1261 알고스팟

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define INF 987654321

using namespace std;
int n, m, anss, temp = INF;
int arr[101][101], wall[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dijk(int a, int b) {

	queue < pair<int, int>>q;
	q.push({ a,b });
	wall[a][b] = 0;

	while (!q.empty()) {

		//cout << "IN" << endl;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;
			//cout << "arr[nx][ny] : " << arr[nx][ny] << endl;
			//cout << "wall[nx][ny] : " << wall[nx][ny] << endl;
			//cout << "wall[x][y] : " << wall[x][y] << endl;
			if (arr[nx][ny] == 1) {	//	벽
				if (wall[nx][ny] > wall[x][y] + 1) {
					//cout << "11" << endl;
					wall[nx][ny] = wall[x][y] + 1;
					q.push({ nx,ny });
				}
			}
			else if (arr[nx][ny] == 0) {	//	벽 아님
				if (wall[nx][ny] > wall[x][y]) {
					//cout << "22" << endl;
					wall[nx][ny] = wall[x][y];
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			wall[i][j] = INF;
			arr[i][j] = str[j] - '0';
		}
	}

	dijk(0, 0);
	cout << wall[n - 1][m - 1] << endl;
}