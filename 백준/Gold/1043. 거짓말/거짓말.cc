//1043 거짓말

#include <iostream>
#include <vector>

using namespace std;
int parent[51];
int n, m, l, anss;
int fact[51];
vector <int> party[51];


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

int main() {
	cin >> n >> m >> l;
	for (int i = 0;i < l;i++)cin >> fact[i];
	for (int i = 0;i < n;i++)parent[i] = i;

	for (int i = 0;i < m;i++) {
		int a, b, prev;
		cin >> a;
		for (int j = 0;j < a;j++) {
			if (j == 0) {
				cin >> b;
			}
			else {
				prev = b;
				cin >> b;
				unio(prev, b);
			}
			party[i].push_back(b);
		}
	}
	int flag = 0;
	for (int i = 0;i < m;i++) {
		int len = party[i].size();
		for (int j = 0;j < len;j++) {
			int now = party[i][j];
			for (int k = 0;k < l;k++) {
				if (find(now) == find(fact[k])) {
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) anss++;
		flag = 0;
	}
	cout << anss << endl;
}