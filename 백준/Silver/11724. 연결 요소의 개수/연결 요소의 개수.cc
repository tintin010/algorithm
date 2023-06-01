//연결 요소의 개수

#include <iostream>
#include <queue>

using namespace std;
int n, m;
int arr[1001][10001];
int visit[1001];
int cnt = 0;
queue <int>q;

void dfs(int a) {
	visit[a] = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[a][i] == 1 && visit[i] == 0)dfs(i);
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << endl;
}