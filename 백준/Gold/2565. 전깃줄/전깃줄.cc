//1932 전깃줄
#include <iostream>

using namespace std;

int len, m;
int arr[501][501];
int line[501];
int dp[501];


int main() {
	cin >> len;
	for (int i = 0; i < len; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		m = max(m, a);
	}
	int temp = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 500; j++) {
			if (arr[i][j]) {
				line[++temp] = j;
				continue;
			}
		}
	}
	int mm = 0;
	for (int i = 1; i <= temp; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (line[j] < line[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		mm = max(mm, dp[i]);
	}
	cout <<temp - mm << endl;
}

