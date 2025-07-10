//15650 n과 m  - 2

#include <iostream>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX],visit[MAX];

void dfs(int num, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	else {
		for (int i = num; i <= n; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				arr[k] = i;
				//cout << "num : " << num  << endl;
				//cout << "k : " << k << endl << endl;
				dfs(i + 1,k + 1);
				visit[i] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}