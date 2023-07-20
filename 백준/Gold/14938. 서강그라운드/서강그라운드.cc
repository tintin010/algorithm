#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;
int arr[101][101], item[101], sm[101];
int n, m, r, anss;

int main() {
	cin >> n >> m >> r;
	for (int i = 0;i <= n;i++)for (int j = 0;j <= n;j++) {
		if (i == j)arr[i][j] = 0;
		else arr[i][j] = INF;
	}
	for (int i = 1;i <= n;i++)cin >> item[i];
	for (int i = 0;i < r;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (arr[i][k] < INF && arr[k][j] < INF) {
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		sm[i] = item[i];
		for (int j = 1;j <= n;j++) {
			if (i != j && arr[i][j] <= m)sm[i] += item[j];
		}
		anss = max(sm[i], anss);
	}
	cout << anss;
}