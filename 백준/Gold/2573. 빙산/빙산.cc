#include <iostream>
#include <queue>

using namespace std;
int arr[301][301];
int vis[301][301];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, cntt;
queue <pair<int, int>>q;



void bfs() {
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int na = dx[i] + a;
			int nb = dy[i] + b;
			if (na > n || nb > m || na <= 0 || nb <= 0 || vis[na][nb]||arr[na][nb] == 0)continue;
			vis[na][nb] = 1;
			q.push({ na, nb });
		}
	}
}

void mbfs() {
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			//cout << "i : " << i << endl;
			int na = dx[i] + a;
			int nb = dy[i] + b;
			if (na > n || nb > m || na <= 0 || nb <= 0 || vis[na][nb])continue;
			if (arr[na][nb] == 0) {
				if (arr[a][b] - 1 >= 0) {
					arr[a][b] = arr[a][b] - 1;
				}else arr[a][b] = 0;
			}
			else {
				vis[na][nb] = 1;
				q.push({ na, nb });
			}
		}
		//cout << a << " : " << b << " : " << arr[a][b] << endl;
	}
}

void init() {
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			vis[i][j] = 0;
		}
	}
}

void melt() {
	init();
	//cout<<"melt"<<endl;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (arr[i][j] > 0 && vis[i][j] == 0) {
				vis[i][j] = 1;
				q.push({ i,j });
				mbfs();
			}
		}
	}

}

bool check() {
	
	init();
	int temp = 1;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (arr[i][j] > 0 && vis[i][j] == 0) {
				if (temp == 1) {
					q.push({ i,j });
					bfs();
					temp = 0;
				}
				else {
					//cout << i << " : " << j << endl;
					//cout << "HERE" << endl;
					return false;
				}
			}
		}
	}
	if (temp == 1) {
		//cout << "IN" << endl;
		cntt = 0;
		return false;
	}
	return true;
}


int main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> arr[i][j];
		}
	}
	while (true) {
		if (check()) {
			melt();//바닷물에 빙산이 녹음
			cntt++;
		}
		else break;
	}
	cout << cntt;
}