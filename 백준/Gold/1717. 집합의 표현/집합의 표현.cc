//1717 집합의 표현

#include <iostream>
#include <vector>

using namespace std;
int parent[1000001];
int n, m;


int find(int k) {
	if (parent[k] == k)return k;
	return parent[k] = find(parent[k]);
}

void unio(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b)parent[a] = b;
	else parent[b] = a;
}

void findParent(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int c, a, b;
	for (int i = 1;i <= n;i++)parent[i] = i;
	while (m--) {
		cin >> c >> a >> b;
		if (!c) {//c == 0;
			unio(a, b);
		}
		else {
			findParent(a, b);
		}
	}
    return 0;
}