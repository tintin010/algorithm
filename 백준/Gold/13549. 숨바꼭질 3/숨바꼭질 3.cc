//13549 숨바꼭질 3
#include <iostream>
#include <deque>
#include <functional>

using namespace std;
int me, su, second, m = 100001;
int visit[100001];
deque <pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int na = q.front().first;
		int sec = q.front().second;
		visit[na] = 1;
		q.pop_front();
		if (na == su) {
			cout << sec << endl;
			break;
		}
		if (na * 2 < 100001 && !visit[na * 2]) {
				q.push_front(make_pair(na * 2, sec));
		}
		
		if (na + 1 < 100001 && !visit[na + 1]) {
				q.push_back(make_pair(na + 1, sec + 1));
		}
		if (na - 1 >= 0 && !visit[na - 1]) {
				q.push_back(make_pair(na - 1, sec + 1));
		}
	}
}

int main() {
	cin >> me >> su;
	q.push_back(make_pair(me, 0));
	
	bfs();
}