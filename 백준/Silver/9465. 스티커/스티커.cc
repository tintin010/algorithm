#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
const int M = 100000;
int N, value[2][M], dp[M][3];
int st(int n, int sta) {
	if (n == N) return 0;
	if (dp[n][sta] != -1)return dp[n][sta];

	int res = st(n + 1, 0);
	if (sta != 1)res = max(res, st(n + 1, 1) + value[0][n]);
	if (sta != 2)res = max(res, st(n + 1, 2) + value[1][n]);

	dp[n][sta] = res;
	return res;
}


int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> value[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++)
				dp[i][j] = -1;
		}
		cout << st(0, 0) << endl;
	}
}