//3079 입국 심사

#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits>

#define LLONG_MAX std::numeric_limits<long long>::max()

using namespace std;

long long fred, desk;
long long ma;
long long darr[100001];
long long answer = LLONG_MAX;


int main() {
	cin >> desk >> fred;
	for (int i = 0; i < desk; i++) {
		cin >> darr[i];
		ma = max(ma, darr[i]);
	}
	long long lp = 1, hp = ma * (fred / desk + 1);
	while (lp <= hp) {
		long long mid = (lp + hp) / 2;
		long long por = 0;
		for (int i = 0; i < desk; i++)
		{
			por += mid / darr[i];
		}
		if (por >= fred) {
			hp = mid - 1;
			answer = min(answer, mid);
		}
		else {
			lp = mid + 1;
		}
	}
	cout << answer << endl;

}