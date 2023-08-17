//12852 1로 만들기 2

#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;
int n;
int arr[1000001];
int root[1000001];
queue <pair<int, int>> q;
vector <int> r;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)arr[i] = INF;
	q.push({ n,0 });

	while (!q.empty()) {
		int k = q.front().first;
		int c = q.front().second;
		q.pop();

		if (k == 1) break;

		if (k%3==0) {
			if (arr[k / 3] > c + 1) {
				arr[k / 3] = c + 1;
				root[k / 3] = k;
			}
			q.push({ k / 3, c + 1 });
		}
		if (k % 2 == 0) {
			if (arr[k / 2] > c + 1) {
				arr[k / 2] = c + 1;
				root[k / 2] = k;
			}
			q.push({ k / 2, c + 1 });
		}
		if (arr[k - 1] > c + 1) {
			arr[k - 1] = c + 1;
			root[k - 1] = k;
		}
		q.push({ k - 1, c + 1 });
	}
	int t = 1;
	while (t) {
		r.push_back(t);
		t = root[t];
	}
	cout << arr[1] << endl;
	for (int i = r.size() - 1; i >= 0; i--) {
		cout << r[i] << " ";
	}
}