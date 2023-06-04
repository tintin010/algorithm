//2630 색종이 만들기

#include <iostream>
#include <vector>

using namespace std;
int n;
int arr[130][130];
int blue = 0;
int white = 0;

void Z(int y, int x, int pos) {
	
	int temp = 0;
	for (int i = y; i < y + pos; i++) {
		for (int j = x; j < x + pos; j++) {
			if (arr[i][j]) {
				temp++;
			}
		}
	}

	if (!temp) white++;
	else if (temp == pos * pos)blue++;
	else {
		Z(y, x, pos / 2);
		Z(y, x + pos / 2, pos / 2);
		Z(y + pos / 2, x, pos / 2);
		Z(y + pos / 2, x + pos / 2, pos / 2);
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	Z(0, 0, n);
	cout << white << endl;
	cout << blue << endl;

}