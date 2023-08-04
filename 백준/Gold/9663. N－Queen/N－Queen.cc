//9663 N-Queen

#include <iostream>
#include <math.h>

using namespace std;
int chess[16], n, cntt;

bool cheek(int x) {
	for (int i = 0;i < x;i++) {
		if (chess[i] == chess[x] || x - i == abs(chess[x] - chess[i])) return false;
	}
	return true;
}

void queen(int cnt) {
	if (cnt == n)cntt++;
	else {
		for (int i = 0;i < n;i++) {
			chess[cnt] = i;
			if (cheek(cnt)) {
				queen(cnt + 1);
			}
		}
	}
}

int main() {
	cin >> n;
	queen(0);
	cout << cntt;
}