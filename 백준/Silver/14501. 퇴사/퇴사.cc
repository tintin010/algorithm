//14501 퇴사 

#include <iostream>

#include <algorithm>
using namespace std;

int arr[16];
int cal[16];
int price[16];
int n, t, p;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t >> p;
		cal[i] = t;
		price[i] = p;
	}
	int dd = 0;
	for (int i = n; i > 0; i--) {
		dd = i + cal[i];
		if (dd > n + 1) {
			arr[i] = arr[i + 1];
		}
		else {
			arr[i] = max(arr[i + 1], arr[dd] + price[i]);
		}
	}
	cout << arr[1] << endl;
}