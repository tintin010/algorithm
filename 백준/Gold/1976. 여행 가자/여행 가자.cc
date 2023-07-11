//1976 여행 가자

#include <iostream>
#include <vector>

using namespace std;
int city[201];
int travel[201];
int n, m, t;

int find(int a) {
	if (city[a] == a)return a;
	return city[a] = find(city[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b)city[a] = b;
	else city[b] = a;
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)city[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> t;//i 나라와 j나라의 연결 여부
			if (t) uni(i, j);
		}
	}

		int flag = 1;
		int temp = 0;
		for (int i = 1; i <= m; i++) {
			int k;
			cin >> k;
			if (i == 1)temp = find(k);
			else {
				if (find(temp) != find(k)) {
					cout << "NO";
						return 0;
				}
			}
		}
		cout << "YES";
	return 0;
}