//1197 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];
int v, r, anss;
vector <pair<int, pair<int, int>>>l;


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
	cin >> v >> r;
	for (int i = 0;i < r;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		l.push_back({ c,{a,b} });//cost, st, ed 순서로 저장
	}
	sort(l.begin(), l.end());//거리를 오름차순으로 정렬함

	for (int i = 1;i <= v;i++)parent[i] = i;
	for (int i = 0;i < l.size();i++) {
		int c = l[i].first;
		int a = l[i].second.first;
		int b = l[i].second.second;
		if (find(a) != find(b)) {
			uni(a, b);
			anss += c;
		}
	}
	cout << anss;
}