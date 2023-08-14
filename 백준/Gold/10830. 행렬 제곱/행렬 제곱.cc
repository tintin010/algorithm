//10830 행렬 제곱

#include <iostream>
#define ll long long

using namespace std;
ll n, b;
ll arr[6][6], te[6][6],anss[6][6];

void mul(ll aa[6][6], ll bb[6][6]) {
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			te[i][j] = 0;
			for (int k = 0;k < n;k++) {
				te[i][j] += (aa[i][k] * bb[k][j]);
			}
			te[i][j] %= 1000;
		}
	}
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			aa[i][j] = te[i][j];
		}
	}
}

int main() {
	cin >> n >> b;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cin >> arr[i][j];
		anss[i][i] = 1;
	}
	while (b > 0) {
		if (b % 2 == 1) {
			mul(anss, arr);
		}
		mul(arr, arr);
		b /= 2;
	}

	for (int i = 0;i < n;i++)	 {
		for (int j = 0;j < n;j++)
			cout << anss[i][j] << " ";
		cout << endl;
	}
}