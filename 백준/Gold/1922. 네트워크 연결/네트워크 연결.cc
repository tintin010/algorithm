//1922 네트워크 연결

//크루스칼 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, anss;
int parent[1001];
vector <pair<int, pair<int, int>>>v;

int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x > y)parent[x] = y;
	else parent[y] = x;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	for (int i = 1;i <= n;i++)parent[i] = i;
	sort(v.begin(), v.end());

	for (int i = 0;i < v.size();i++) {
		int cost = v[i].first;
		int st = v[i].second.first;
		int ed = v[i].second.second;
		if (find(st) == find(ed))continue;
		uni(st, ed);
		anss += cost;
	}
	cout << anss;
	return 0;
}