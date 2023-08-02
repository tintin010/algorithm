//9184 신나는 함수 실행

#include <iostream>

using namespace std;
int t1, t2, t3;
int mem[21][21][21];

int re(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;

	if (a > 20 || b > 20 || c > 20)
		return re(20, 20, 20);

	if (mem[a][b][c])
		return mem[a][b][c];

	if (a < b && b < c) {
		mem[a][b][c] = re(a, b, c - 1) + re(a, b - 1, c - 1) - re(a, b - 1, c);
		return mem[a][b][c];
	}

	mem[a][b][c] = re(a - 1, b, c) + re(a - 1, b - 1, c) + re(a - 1, b, c - 1) - re(a - 1, b - 1, c - 1);
	return mem[a][b][c];
}

int main() {
	while (1) {
		cin >> t1 >> t2 >> t3;
		if (t1 == -1 && t2 == -1 && t3 == -1)
			break;
		cout << "w(" << t1 << ", " << t2 << ", " << t3 << ") = " << re(t1, t2, t3) << '\n';
	}
	
}