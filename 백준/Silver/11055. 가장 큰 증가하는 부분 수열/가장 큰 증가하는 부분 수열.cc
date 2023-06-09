//11055 가장 큰 증가하는 부분 수열
#include <iostream>
#include <algorithm>
using namespace std;

int n, sum = 0;
int arr[1001];
int dp[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + arr[i], dp[i]);
			}
		}
		sum = max(sum, dp[i]);
	 }
	cout << sum << endl;
	return 0;
}