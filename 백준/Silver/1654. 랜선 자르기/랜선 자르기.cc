//1654 랜선 자르기

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n, cn;
long long len[10001];
long long answer = 0;


int main() {
	cin >> n >> cn;
	long long m1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> len[i];
		m1 = max(m1, len[i]);
	}
	long long lp = 1, hp = m1;
	while (lp <= hp) {
		long long por = 0;
		long long mid = (lp + hp) / 2;
		for (int i = 0; i < n; i++) {
			por += len[i] / mid;
		}
		if (por >= cn) {
			lp = mid + 1;
			answer = max(answer, mid);
		}
		else {
			hp = mid - 1;
		}
	}

	cout << answer << endl;

}