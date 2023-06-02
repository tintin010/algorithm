//1074 Z

#include <iostream>
#include <vector>

using namespace std;
int n, r, c;
int ans = 0;

void Z(int y,int x,int pos) {
	if (y == r && x == c) {
		cout << ans << endl;
		return;
	}
	if (r < y + pos && c < x + pos && r >= y && c >= x) {
		Z(y, x, pos / 2);
		Z(y, x + pos / 2, pos / 2);
		Z(y + pos / 2, x, pos / 2);
		Z(y + pos / 2, x + pos / 2, pos / 2);
	}
	else {
		ans += pos * pos;
	}
}

int main() {
	cin >> n>>r>>c;
	Z(0, 0, (1 << n));

}