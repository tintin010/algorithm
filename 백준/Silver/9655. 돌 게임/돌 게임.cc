//9655 돌 게임

#include <iostream>

using namespace std;
int n;
int dp[1001];
int main() {
	//해당 코드는 간편하게 게임 횟수로 푼 문제
	/*cin >> n;
	if (n % 2 == 0)cout << "CY" << endl;
	else cout << "SK" << endl;*/

	// DP
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}
	if (dp[n] % 2 == 0)cout << "CY" << endl;
	else cout << "SK" << endl;
}