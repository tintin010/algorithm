//2589 보물선

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, anss;
int vis[51][51];
char arr[51][51];
queue <pair<int, int>>q;

void init() {
	for (int i = 1;i <= n;i++)for (int j = 1;j <= m;j++)vis[i][j] = 0;
}

//bool ch(int a, int b) {
//	int temp = 0;
//	for (int i = 0;i < 4;i++) {
//		if (arr[a + dx[i]][b + dy[i]] == 'L')temp++;
//	}
//	if (temp == 1)return true;
//	return false;
//}

void bfs() {
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		anss = max(anss, vis[a][b] - 1);
		//cout << a << " : " << b << endl;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (na <= 0 || nb <= 0 || na > n || nb > m || vis[na][nb] > 0 || arr[na][nb] == 'W')continue;
			q.push({ na,nb });
			vis[na][nb] = vis[a][b] + 1;
			
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		string str;
		cin >> str;
		for (int j = 1;j <= m;j++) {
			arr[i][j] = str[j - 1];
		}
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (!vis[i][j] && arr[i][j] == 'L') {
					q.push({ i,j });
					vis[i][j] = 1;
					bfs();
					init();
			}
		}
	}
	cout << anss;
}