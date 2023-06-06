//2583 영역 구하기

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector <int>v;
queue <pair<int, int>> q;

int arr[101][101];
int visit[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, k;

void BFS(int a,int b) {
	q.push(make_pair(a, b));
	int count = 1;
	visit[a][b] = 1;
	while (!q.empty()) {
		int coloum = q.front().first;
		int row = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int c = coloum + dy[i];
			int r = row + dx[i];
			if (c >= 0 && r >= 0 && c <n && r <m && visit[c][r] == 0 && arr[c][r]>=0) {
				visit[c][r] = 1;
				q.push(make_pair(c, r));
				count++;
			}
		}

	}
	v.push_back(count);
}


int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = 0; j < d - b; j++) {
			for (int k = 0; k < c - a; k++) {
				arr[b + j][a + k] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] >= 0 && visit[i][j] == 0) {
				BFS(i, j);
			}
		}
	}

	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}