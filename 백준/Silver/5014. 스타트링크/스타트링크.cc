//5014 스타트링크

#include <iostream>
#include <queue>

using namespace std;

int	f, s, g, u, d, flag;//총 층수, 현재 위치, 목적지, 위, 아래
int vis[1000001];
queue <int>q;


void bfs() {
	while (!q.empty()) {
		int a = q.front();
		int c = vis[a];
		q.pop();
		if (a == g) {
			flag = 1;
			while (!q.empty())q.pop();
			continue;
		}

		if (a - d > 0 && vis[a - d] == 0) {
			q.push(a - d);
			vis[a - d] = c + 1;
		}
		if (a + u <= f && vis[a + u] == 0) {
			q.push(a + u);
			vis[a + u] = c + 1;
		}
	}
}

int main() {
	cin >> f >> s >> g >> u >> d;
	q.push(s);
	vis[s] = 1;
	bfs();
	if (flag) {
		cout << vis[g] - 1 << endl;
	}
	else cout << "use the stairs" << endl;
}