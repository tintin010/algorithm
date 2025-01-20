//2792 보석 상자

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long gem_c, stc;
long long gem[300001];
long long answer = 1000000001;

int main() {
	cin >> stc >> gem_c;
	long long ma = 0;
	for (int i = 0; i < gem_c; i++) {
		cin >> gem[i];
		ma = max(ma, gem[i]);
	}
	long long lp = 1, hp = ma;

	while (hp >= lp) {
		long long por = 0;
		long long mid = (lp + hp) / 2;
		for (int i = 0; i < gem_c; i++) {
			por += gem[i] / mid;
			if (gem[i] % mid > 0)por += 1;
		}
		if (por <= stc) {
			hp = mid - 1;
			answer = min(answer, mid);
		}
		else {
			lp = mid + 1;
		}
	}
	cout << answer << endl;
}