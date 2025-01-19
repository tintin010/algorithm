//15652 n과 m  - 4

#include <iostream>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX], visit[MAX];

void FUNC(int num, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	else {
		for (int i = num; i <= n; i++) {

				arr[k] = i;
				FUNC(i, k + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	FUNC(1, 0);
}