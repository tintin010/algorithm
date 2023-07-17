#include <iostream>

using namespace std;
int cnt, n;

int main() {
	cin >> n;
	cnt = 0;
	int dayy = 0;
	while (n > 0)
	{
		if (n - cnt > 0) {
			cnt++;
			dayy++;
			n = n - cnt;
		}
		else {
			cnt = 1;
			dayy++;
			n = n - cnt;
		}
	}
	cout << dayy;
}