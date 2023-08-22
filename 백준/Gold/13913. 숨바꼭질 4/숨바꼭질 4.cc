//13913 숨바꼭질4 -re-

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int me, su, second;
int visit[1000001], root[1000001];
queue <pair<int, int>> q;
vector <int> vec;

void bfs() {
	while (!q.empty()) {
		int na = q.front().first;
		int sec = q.front().second;
		q.pop();
		if (na == su) {
			cout << sec << endl;
			break;
		}
		if (na + 1 < 200001) {
			if (visit[na + 1] == 0) {
				visit[na + 1] = 1;
				root[na + 1] = na;
				q.push(make_pair(na + 1, sec + 1));
			}
		}
		if (na - 1 >= 0) {
			if (visit[na - 1] == 0) {
				visit[na - 1] = 1;
				root[na - 1] = na;
				q.push(make_pair(na - 1, sec + 1));
			}
		}
		if (na * 2 < 200001) {
			if (visit[na * 2] == 0) {
				visit[na * 2] = 1;
				root[na * 2] = na;
				q.push(make_pair(na * 2, sec + 1));
			}
		}
	}
}

int main() {
	cin >> me >> su;
	q.push(make_pair(me, 0));
	visit[me] = 1;
	bfs();
	int t = su;
	while (t != me) {
		vec.push_back(t);
		t = root[t];
	}
	cout << me << " ";
	for (int i = vec.size() - 1; i >= 0; i--) {
		cout << vec[i] << " ";
	}
	cout << endl;
}