//14940 쉬운 최단거리

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
queue< pair<int, int>> q;
int arr[1001][1001];
int road[1001][1001];
int visit[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;

void BFS() {
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		visit[a][b] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int c = a + dy[i];
			int r = b + dx[i];
			if (c > 0 && r > 0 && c <= n && r <= m && visit[c][r] == 0 && road[c][r] == 1) {
				visit[c][r] = 1;
				arr[c][r] = arr[a][b] + 1;
				q.push(make_pair(c, r));
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> road[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (road[i][j] == 2) {
				q.push(make_pair(i, j));
				BFS();
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (road[i][j] == 1&&arr[i][j]==0) {
				arr[i][j] = -1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}

}