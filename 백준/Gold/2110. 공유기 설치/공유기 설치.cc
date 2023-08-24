//2110 공유기 설치 -RE-

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, c, anss = 0;
int home[200001];
vector <int> v;

int main() {
	cin >> n >> c;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		v.push_back(a);

	}
	sort(v.begin(), v.end());
	int l = 1;//첫번째 공유기와 첫번째 공유기 사이 거리
	int r = v[n - 1] - v[0];//첫번째 공유기와 마지막 공유기 사이 거리

	while (l <= r) {
		int cntt = 1;
		int mid = (r + l) / 2;
		int st = v[0];
		for (int i = 0;i < n;i++) { //0 to n-2
			if (v[i] - st >= mid) {
				st = v[i];
				cntt++;
			}
		}
		if (cntt >= c) {
			anss = max(anss, mid);
			l = mid + 1;
			//cout << "r : " << r << endl;
		}
		else {
			r = mid - 1;
			//cout << "l : " << l << endl;
		}
	}
	cout << anss << endl;


}