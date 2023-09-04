#include <iostream>

using namespace std;
int a, b, c, st;

int search() {
	for (int i = 0;i <= 50;i++) {
		int t1 = i * a;
		for (int j = 0;j <= 50;j++) {
			int t2 = j * b;
			for (int k = 0;k <= 50;k++) {
				int t3 = k * c;
				if (t1 + t2 + t3 == st) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	cin >> a >> b >> c >> st;
	cout << search() << endl;
}