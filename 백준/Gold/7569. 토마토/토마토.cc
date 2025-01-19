#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int visit[101][101][101];
int arr[101][101][101];
int n, m, h, day = 0;;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

tuple<int, int, int> t;
queue < tuple<int, int, int> > q;

void bfs() {
	while (!q.empty()) {
		int size = q.size();
		day++;
		for(int s = 0; s < size; s++){
			int a = get<0>(q.front());
			int b = get<1>(q.front());
			int c = get<2>(q.front());
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = dx[i] + a;
				int ny = dy[i] + b;
				int nz = dz[i] + c;
				if (nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h && arr[nz][ny][nx] == 0) { //arr[nz][ny][nx] == 0 &&
					arr[nz][ny][nx] = day;
					q.push(make_tuple(nx, ny, nz));
				}
			}
		}
	}
}

int main() {

	cin >> n >> m >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push(make_tuple(k, j, i));
				}
			}
		}
	}
	bfs();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[i][j][k] == 0) day = 0;
			}
		}
	}
	cout << day - 1 << endl;
	return 0;
}
