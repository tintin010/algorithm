//9205 맥주 마시면서 걸어가기
/*
편의점을 주어진 순서대로 다녀오라는 말이 없는데 착각함
그러면 길을 미리 연결해 두고 해당 길을 갈 수 있는지 판단해야함.

*/

#include <iostream>
#include <queue>
#include <math.h>

using namespace std;
int t, m, hx, hy, disx, disy;
int vis[101];
vector <pair<int, int>>q;

void init() {
	for (int i = 0; i <= 100; i++)vis[i] = 0;
}

void bfs() {
	queue <pair<int, int>>temp;
	temp.push({ hx,hy });
	while (!temp.empty()) {
		int tx = temp.front().first;
		int ty = temp.front().second;
		temp.pop();

		int dis = abs(tx - disx) + abs(ty - disy);
		//cout << "dis : " << dis << endl;
		if(dis <=1000) {
			cout << "happy" << endl;
			return;
		}
		for (int i = 0; i < q.size(); i++) {
			if (vis[i] == 1)continue;
			if (abs(q[i].first - tx) + abs(q[i].second - ty) <= 1000) {
				vis[i] = 1;
				temp.push({ q[i].first, q[i].second });
			}
		}
	}
	cout << "sad" << endl;
	return;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> m;
		cin >> hx >> hy;
		for (int i = 0; i < m; i++) {
			int mx, my;
			cin >> mx >> my;
			q.push_back({ mx,my });
		}
		cin >> disx >> disy;
		bfs();
		init();
		while (!q.empty())q.pop_back();
	}
}