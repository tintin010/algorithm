//2636 치즈


#include <iostream>
#include <queue>

using namespace std;
int n, m, flag, cntt, temp, dayy;
int arr[101][101];
int vis[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void melt();
void bfs();
void sea();		//바다인지 판단
void init();	//vis 리셋
queue <pair<int, int>>se, q;

void init() {
	for (int i = 1;i <= n;i++)for (int j = 1;j <= m; j++) vis[i][j] = 0;
}

void sea() {
	se.push({ 1,1 });
	arr[1][1] = 2;
	vis[1][1] = 1;
	while (!se.empty()) {
		int a = se.front().first;
		int b = se.front().second;
		se.pop();
		for (int i = 0;i < 4;i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (na <= 0 || nb <= 0 || na > n || nb > m || vis[na][nb])continue;
			if (arr[na][nb] == 2 || arr[na][nb] == 0) {
				se.push({ na,nb });
				arr[na][nb] = 2;
				vis[na][nb] = 1;
			}
		}
	}
}

void bfs() {
	flag = 1;//치즈가 존재하여 bfs 진입
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		cntt++;
		//cout << a << " : " << b <<" : "<< cntt << endl;
		for (int i = 0;i < 4;i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (na <= 0 || nb <= 0 || na > n || nb > m || vis[na][nb])continue;
			if (arr[na][nb] == 2) {
				arr[a][b] = 2;
				//vis[na][nb] = 1;
			}
			else if(arr[na][nb] == 1) {
				vis[na][nb] = 1;
				q.push({ na,nb });
			}
		}
	}
}

void melt() {
	while (1) {
		sea();	// 바다를 판단
		init();
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				if (arr[i][j] == 1 && !vis[i][j]) {
					q.push({ i,j });
					vis[i][j] = 1;
					bfs();
				}
			}
		}
		
		if (flag)dayy++;
		else {
			cout << dayy << endl;
			cout << temp << endl;
			return;
		}
		temp = cntt;
		flag = 0;
		cntt = 0;
		init();
	}
}


int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++)for (int j = 1;j <= m; j++)cin >> arr[i][j];
	melt();
}