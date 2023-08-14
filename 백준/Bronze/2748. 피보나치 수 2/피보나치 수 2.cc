//2748 피보나치 수 2 - DP-

#include <iostream>
#define ll long long

using namespace std;
ll dp[91], n;

int main() {
	cin >> n;

	dp[1] = 1;
	for (int i = 2;i <= n;i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
}