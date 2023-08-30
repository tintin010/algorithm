//2343 기타 레슨

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, mxx, anss = 987654321;
int arr[100001];

int cal(int mid) {
	int cntt = 1;
	int temp = 0;
	for (int i = 0;i < n;i++) {
		if (temp + arr[i] > mid) {
			temp = arr[i], cntt++;
		}
		else {
			temp += arr[i];
		}
	}
	return cntt;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		mxx = max(mxx, arr[i]);
	}
	int r = mxx * n;
	int l = mxx;

	while (l<=r) {
		int mid = (r + l) / 2;
		int cntt = cal(mid);
		if (cntt > m) {
			l = mid + 1;
		}
		else if (cntt <= m) {
			anss = min(anss, mid);
			r = mid - 1;
		}
	}
	cout << anss << endl;
}