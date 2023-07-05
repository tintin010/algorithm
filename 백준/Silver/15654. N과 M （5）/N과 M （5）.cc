//15654 n과m - 5

#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;
int n, m;
int mm[MAX];
int arr[MAX], visit[MAX];

void dfs(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				arr[k] = mm[i];
				//cout << "num : " << num  << endl;
				//cout << "k : " << k << endl << endl;
				dfs(k + 1);
				visit[i] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> mm[i];
	sort(mm, mm + n);
	dfs(0);
}