//1389 베이컨

#include <iostream>

using namespace std;
const int INF = 987654321;
int n, m, a, b;
int arr[101][101];
int ans[101];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j && !arr[i][j])
				arr[i][j] = INF;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] && arr[k][j]) {
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
	}
	int mm = 101, coun = 1e9;
	for (int i = 1; i <= n; i++) {
		int anss = 0;
		for (int j = 1; j <= n; j++) {
			anss += arr[i][j];
		}
		if (coun > anss) {
			coun = anss;
			mm = i;
		}
	}
	cout << mm << endl;
}