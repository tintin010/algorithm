//1987 알파벳

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int r, c, anss = 0;
char arr[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int alp[26];

void dfs(int x, int y, int dis) {	// 백트래킹 이용하기

	anss = max(anss, dis);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c || alp[(int)arr[nx][ny] - 65])continue;
		alp[(int)arr[nx][ny] - 65]++;
		dfs(nx, ny, dis + 1);
		alp[(int)arr[nx][ny] - 65]--;
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s1;
		cin >> s1;
		for (int j = 0; j < c; j++) arr[i][j] = s1[j];
	}
	alp[(int)arr[0][0] - 65]++;
	dfs(0, 0, 1);
	cout << anss << endl;
}
