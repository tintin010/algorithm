//14940 쉬운 최단거리

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
queue< pair<int, int>> q;
char camp[601][601];
int visit[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, cntt = 0;

void BFS() {
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		visit[a][b] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int c = a + dy[i];
			int r = b + dx[i];
			if (c > 0 && r > 0 && c <= n && r <= m && visit[c][r] == 0 && camp[c][r] != 'X') {
				visit[c][r] = 1;
				if(camp[c][r]=='P')cntt++;
				q.push(make_pair(c, r));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str = "";
		cin >> str;
		for (int j = 1; j <= m; j++) {
			camp[i][j] = str[j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (camp[i][j] == 'I') {
				q.push(make_pair(i, j));
				BFS();
			}
		}
	}
	if (cntt == 0)cout << "TT" << endl;
	else cout << cntt << endl;
}