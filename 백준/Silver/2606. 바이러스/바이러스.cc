// 바이러스

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[101];

int main(void) {
	queue<int> q;
	int st = 0;
	int rep = 0;
	cin >> st;
	cin >> rep;
	vector<vector<int>> vec(st +1, vector<int>()); // 벡터 배열 동적 생성
	for (int i = 0; i < rep; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	q.push(1);
	visited[1] = 1;
	int count = 0;
	while (!q.empty()) {
		int fr = q.front();
		q.pop();
		for (int i = 0; i < vec[fr].size(); i++) {
			int k = vec[fr][i];
			if (!visited[k]) {
				visited[k] = 1;
				q.push(k);
				count++;
			}
		}
	}
	cout << count;

}