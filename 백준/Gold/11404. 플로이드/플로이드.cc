#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;
int n, m, a, b, c;
int city[104][104];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) {
		if (i == j) city[i][j] = 0;
		else city[i][j] = INF;
	}
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;
		city[a][b] = min(city[a][b], c);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (city[i][k] != INF && city[k][j] != INF)
					city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (city[i][j] == INF) cout << 0 << " ";
			else cout << city[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
			
}