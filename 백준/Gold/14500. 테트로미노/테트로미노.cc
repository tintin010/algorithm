//14500 테트로미노

#include <iostream>
#include <queue>
#include <string>

using namespace std;
int arr[501][501];
int visit[501][501];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int n, m, maxx = 0;

void dfs(int a, int b, int cnt, int score) {
	if (cnt == 4) {
		maxx = max(maxx, score);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ni = dy[i] + a;
		int nj = dx[i] + b;
		if (ni<1 || nj<1 || ni>n || nj>m || visit[ni][nj] == 1)continue;
		visit[ni][nj] = 1;
		dfs(ni, nj, cnt + 1, arr[ni][nj] + score);
		visit[ni][nj] = 0;
	}
	if (a - 1 >= 1 && b - 1 >= 1 && a + 1 <= n) { //ㅓ
		maxx = max(maxx, (arr[a - 1][b] + arr[a][b - 1] + arr[a][b] + arr[a + 1][b]));
	}
	if (a - 1 >= 1 && a + 1 <= n && b + 1 <= m) { //ㅏ
		maxx = max(maxx, (arr[a + 1][b] + arr[a][b + 1] + arr[a][b] + arr[a - 1][b]));
	}
	if (a - 1 >= 1 && b - 1 >= 1 && b + 1 <= m) { //ㅗ
		maxx = max(maxx, (arr[a - 1][b] + arr[a][b - 1] + arr[a][b] + arr[a][b + 1]));
	}
	if (b - 1 >= 1 && a + 1 <= n && b + 1 <= m) { //ㅜ
		maxx = max(maxx, (arr[a + 1][b] + arr[a][b - 1] + arr[a][b] + arr[a][b + 1]));
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)cin >> arr[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visit[i][j] = 1;
			dfs(i, j, 1, arr[i][j]);
			visit[i][j] = 0;
		}
	}
	cout << maxx << endl;
}