#include <iostream>
#include <queue>

using namespace std;
int arr[101];
int map[101];
int n, m, a, b;
queue <int>q;

void bfs() {
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int nk = k + i;
			if (nk > 100)continue;
			else if (nk == 100) {
				map[nk] = map[k] + 1;
				cout << map[100] << endl;
				while (!q.empty())q.pop();
				break;
			}
			else {
				while (arr[nk] > 0) {
					nk = arr[nk];
				}
				if (map[nk] == 0) {
					map[nk] = map[k] + 1;
					//cout << "nk : " << nk << endl;
					q.push(nk);
				}
			}
		}
	}
}

int main() {
	for (int i = 1; i <= 100; i++)arr[i] = -1;
	for (int i = 1; i <= 100; i++)map[i] = 0;
	cin >> n >> m;
	for (int i = 0; i < m + n; i++) {
		cin >> a >> b;
		arr[a] = b;
	}
	q.push(1);
	map[1] = 0;
	bfs();

}