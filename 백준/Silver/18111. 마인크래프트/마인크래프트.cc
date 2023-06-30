//18111 마인크래프트

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m, b;
int arr[501][501];
int maxx = 0, ans = 0x7f7f7f7f, hh = 0;

int main() {
	cin >> n >> m >> b;
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++) {
		cin >> arr[i][j];
	}
	int cnt = 0;
	for (int h = 0; h <= 256; h++) {
		int build = 0;
		int remove = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int height = arr[i][j] - h;
				if (height > 0) remove += height;
				else if (height < 0) build -= height;
			}
		}
		int temp = 0;
		if (remove + b >= build) {
			temp = remove * 2 + build;
			if (ans >= temp) {
				ans = temp;
				hh = h;
			}
		}
	}
	cout << ans << " " << hh << endl;

}
