#include <iostream>
#include <algorithm>

using namespace std;
int dp[100001][3];
int len = 0;


int main() {
	cin >> len;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for (int i = 2; i <= len; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2])%9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
	}
	int result = (dp[len][0] + dp[len][1] + dp[len][2])%9901;
	cout << result << endl;


}