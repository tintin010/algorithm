#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

long long arr[1000001];
long long cnt[1001] = { 0 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i + 1] = (arr[i] + a) % m;
		cnt[arr[i + 1]]++;
	}
	long long ans = cnt[0];
	for (int i = 0; i < m; i++) {
		ans += (cnt[i] * (cnt[i] - 1)) / 2;
	}
	cout << ans << "\n";
}