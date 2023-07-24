#include <iostream>

using namespace std;

int n, st, ed;
char arr[3072][6143];

void draw(int i, int j) {
	arr[i][j] = '*';

	arr[i + 1][j - 1] = '*';
	arr[i + 1][j + 1] = '*';

	for (int k = 0;k < 5;k++) {
		arr[i + 2][j - 2 + k] = '*';
	}

}

void rec(int i, int j, int n) {

	if (n == 3) {
		draw(i, j);
		return;
	}

	rec(i, j, n / 2);
	rec(i + n / 2, j - n / 2, n / 2);
	rec(i + n / 2, j + n / 2, n / 2);

}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++)for (int j = 0;j < 2 * n - 1;j++)arr[i][j] = ' ';
	rec(0, n - 1, n);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 2 * n - 1;j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}
		