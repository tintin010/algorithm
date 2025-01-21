//병사 배치하기
#include <iostream>

using namespace std;

int n;
int arr[2001];
int dp[2001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (dp[i]<dp[j] + 1 && arr[j]>arr[i])
				dp[i] = dp[j] + 1;
		}
	}
	int m = 0;
	for (int i = 1; i <= n; i++) m = max(m, dp[i]);
	cout << n - m << endl;
}