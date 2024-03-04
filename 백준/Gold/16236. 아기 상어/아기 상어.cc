//16236 아기 상어
//근데 시간초과
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
void solve();
bool srch();
bool route();

int n, wei = 2, cntt, r_cnt, anss = 0;
int c, r;	//	상어 현재위치
int fis_x, fis_y;
int arr[21][21], vis[21][21];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


void solve() {

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 9) {
				c = i, r = j;	//아기 상어 위치 찾기
				arr[i][j] = 0;
			}
		}
	}

	while (srch()) {// 먹을 수 있는 물고기가 있나?
		//cout << "fis_x : " << fis_x << "  " << "fis_y : " << fis_y << endl;

		if (route()) {
			c = fis_x, r = fis_y; // 상어 위치 업데이트
			arr[c][r] = 0;	//	물고기 먹었으면 그 위치는 0이 됨
			cntt++;	//먹은 물고기 개수
			//cout << "cntt -> " << cntt << " : " << " wei -> " << wei << endl;
			if (cntt == wei)wei++, cntt = 0;	//	상어 사이즈 업
		}
		else break;
		//if (wei == 4)break;
	}
}

bool route() {	//물고기까지 갈 수 있으면 true
	for (int i = 0;i < n;i++)for (int j = 0;j < n;j++)vis[i][j] = 0;	//	array vis -> reset
	queue <pair<pair <int, int>, int>>b;	//	x좌표, y좌표, 거리
	b.push({ {c,r},0 });
	vis[c][r] = 1;

	while (!b.empty()) {
		int x = b.front().first.first;
		int y = b.front().first.second;
		int dis = b.front().second;
		b.pop();

		if (x == fis_x && y == fis_y) {
			r_cnt += dis;
			//cout << "r_cnt : " << r_cnt << endl;
			return true;
		}
		//물고기 까지 이동하는데 우선순위를 지정한 뒤 이동을 하는 편이 더 좋은가? 애초에 그게 가능한가?
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//cout << "nx : " << nx << "ny : " << ny << "\n";
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] == 1 || arr[nx][ny] > wei) continue;
			else {
				//cout << "nx : " << nx << " :: " << "ny : " << ny << "\n";
				vis[nx][ny] = 1;
				b.push({ { nx,ny }, dis + 1 });
			}
		}
	}
	return false;
}

int check(int fx, int fy) {//물고기 후보
	for (int i = 0;i < n;i++)for (int j = 0;j < n;j++)vis[i][j] = 0;	//	방문 배열 리셋
	queue <pair<pair <int, int>, int>>b;	//	x좌표, y좌표, 거리
	b.push({ {c,r},0 });
	vis[c][r] = 1;
	while (!b.empty()) {
		int x = b.front().first.first;
		int y = b.front().first.second;
		int dis = b.front().second;
		b.pop();

		if (x == fx && y == fy) {
			//r_cnt += dis;
			return dis;
		}
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] == 1) continue;
			if (arr[nx][ny] > wei)continue;	//	상어보다 큰 물고기가 있으면 못감
			vis[nx][ny] = 1;
			b.push({ { nx,ny }, dis + 1 });
		}
	}
	return 987654321;
}

bool srch() {//먹을 수 있는 물고기가 있으면 TRUE, 가까운 물고기부터 먹음
	//cout << "start" << endl;
	int tx = -1, ty = -1;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] < wei && arr[i][j] > 0) {
				if (tx == -1 && ty == -1) {
					tx = i, ty = j;
					continue;
				}
				int cn = check(i, j);
				int co = check(tx, ty);
				if (cn < co) {	//	새로 찾은 물고기의 거리가 더 가깝다면
					tx = i, ty = j;
				}
				else if (cn == co) {
					if (tx > i)tx = i, ty = j;
					else if (tx == i)
						if (ty > j)tx = i, ty = j;
				}
			}
		}
	}
	if (tx == -1 && ty == -1) return false;
	fis_x = tx, fis_y = ty;
	//이후에 찾아갈 물고기 후보는 문제없이 선정됨.
	//cout << "fish_x : " << fis_x << " :: " << " fish_y : " << fis_y << "\n";

	return true;
}


int main() {
	cin >> n;
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) cin >> arr[i][j];
	solve();
	cout << r_cnt << endl;
}