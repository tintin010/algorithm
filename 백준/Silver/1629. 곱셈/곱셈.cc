//1629 곱셈

#include <iostream>

using namespace std;
long long n, m;
long long a, b, c;

int cal(long long a, long long b) {
	if (b == 1)return a % c;

	n = cal(a, b / 2);
	n = (n * n) % c;
	if (b % 2)n = (n * a) % c;
	return n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	cout << cal(a, b);

}