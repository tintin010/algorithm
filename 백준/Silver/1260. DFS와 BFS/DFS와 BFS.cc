//단지 번호 붙이기
#include <iostream>
#include <queue>
#include <string.h>
// #include <vector>
#include <algorithm>

using namespace std;

int n, m, st;
queue <int> q;
int line[1001][1001];
bool visit[1001];


void DFS(int st) {
	cout << st << " ";
	visit[st] = 1;
	for (int i = 1; i <= n; i++) {
		if (line[st][i] == 1 && visit[i] == 0) DFS(i);
		if(i == n) return;
	}
}

void BFS(int st) {
	q.push(st);
	// visit[st] = 1;
	// cout << st << " ";
	while (!q.empty()) {
		int t = q.front();
		visit[t] = 1;
		cout << t << " ";
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (line[t][i] == 1 && visit[i] == 0) {
				q.push(i);
				visit[i] = 1;
				// cout << i << " ";
			}
		}
	}
}



int main() {
	cin >> n >> m >> st;
	for (int i = 0; i < m; i++) {
		int t1 = 0, t2 = 0;
		cin >> t1 >> t2;
		line[t1][t2] = 1;
		line[t2][t1] = 1;
	}
	
	DFS(st);
	cout << endl;
	// memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= n; i++)visit[i] = 0;
	BFS(st);

}