//DSLR 9019

#include <iostream>
#include <queue>
#include <string>
#include <memory.h>

using namespace std;

int t, a, b;
int visit[10000];

void bfs() {
	queue <pair<int, string>> q;
	q.push(make_pair(a, ""));
	visit[a] = 1;

	while (!q.empty()) {
		int cn = q.front().first;
		string op = q.front().second;
		q.pop();
		if (cn == b) {
			cout << op << endl;
			return;
		}

		int d, s, l, r;
		d = (cn * 2) % 10000;
		if (!visit[d]) {
			visit[d] = 1;
			q.push(make_pair(d, op + "D"));
		}
		s = cn - 1 < 0 ? 9999 : cn - 1;
		if (!visit[s]) {
			visit[s] = 1;
			q.push(make_pair(s, op + "S"));
		}
		l = (cn % 1000) * 10 + (cn / 1000);
		if (!visit[l]) {
			visit[l] = 1;
			q.push(make_pair(l, op + "L"));
		}
		r = cn / 10 + (cn % 10) * 1000;
		if (!visit[r]) {
			visit[r] = 1;
			q.push(make_pair(r, op + "R"));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	
	while (t--) {
		cin >> a >> b;
		memset(visit, false, sizeof(visit));
		bfs();
	}
}