//12851 숨바꼭질 2
#include <iostream>
#include <queue>

using namespace std;
int me, su, second, anss;
int fin_se = 0;
int visit[100001];
queue <pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int na = q.front().first;
		int sec = q.front().second;
		q.pop();


		visit[na] = 1;

		if (na == su) {
			visit[su] = 0;
			if (fin_se == 0) {
				fin_se = sec;
				anss++;
				continue;
			}
			if (fin_se == sec) {
				anss++;
				continue;
			}
		}
		if (na + 1 < 100001 && fin_se == 0) {
			if (visit[na + 1] == 0) {
				q.push(make_pair(na + 1, sec + 1));
			}
		}
		if (na - 1 >= 0 && fin_se == 0) {
			if (visit[na - 1] == 0) {
				q.push(make_pair(na - 1, sec + 1));
			}
		}
		if (na * 2 < 100001 && fin_se == 0) {
			if (visit[na * 2] == 0) {
				q.push(make_pair(na * 2, sec + 1));
			}
		}
	}


}

int main() {
	cin >> me >> su;
	q.push(make_pair(me, 0));
	bfs();
	cout << fin_se << "\n" << anss << endl;
}