// 1865 웜홀 -re-
//벨만 포드 알고리즘 이용해야함

#include <iostream>
#include <vector>
#include <string>
#define INF 987654321

using namespace std;
int n, m, x, t;
string str;
int dis[501];

vector <pair<pair<int, int>, int>>v;

void init() {
	for (int i = 0;i <= 500;i++)dis[i] = -1;

	v.clear();
}

string check() {

	for (int j = 0;j < v.size();j++) {
		int from = v[j].first.first;
		int to = v[j].first.second;
		int co = v[j].second;
		//if (dis[from] == -1)continue;
		if (dis[to] > dis[from] + co) {
			return "YES";
		}
	}
	return "NO";
}

int main() {
	cin >> t;
	while (t--) {
		init();
		cin >> n >> m >> x;
		for (int i = 0;i < m;i++) {
			int st, ed, cost;
			cin >> st >> ed >> cost;
			v.push_back({{ st, ed},cost});
			v.push_back({{ ed, st},cost});
		}
		for (int i = 0;i < x;i++) {
			int st, ed, cost;
			cin >> st >> ed >> cost;
			v.push_back({ { st, ed}, -cost });
		}
		dis[1] = 0;
		for (int i = 0;i < n - 1;i++) {
			for (int j = 0;j < v.size();j++) {
				int from = v[j].first.first;
				int to = v[j].first.second;
				int co = v[j].second;
				//if (dis[from] == -1)continue;
				if (dis[to] > dis[from] + co)dis[to] = dis[from] + co;
			}
		}
		str = check();
		cout << str << endl; 
	}
}