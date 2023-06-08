//1010 다리 놓기

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int t, a, b;


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		int res = 1, tmp = 1;
		for (int j = b; j > b - a; j--) {
			res = res * j;
			res = res / tmp++;
		}
		cout << res << endl;
	}
}