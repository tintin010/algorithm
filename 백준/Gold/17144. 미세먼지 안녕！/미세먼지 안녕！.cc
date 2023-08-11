//17144 미세먼지 안녕!	-re-

#include <iostream>

using namespace std;
int arr[51][51], add[51][51];

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { -1, 0, 1, 0 };
int r, c, t, up, down, tot;

void dust() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int cntt = 0;
			int val = arr[i][j] / 5;
			if (arr[i][j] == 0 || arr[i][j] == -1) continue;
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (nr <= 0 || nc <= 0 || nr > r || nc > c || arr[nr][nc] == -1)continue;
				add[nr][nc] += val;
				cntt++;
			}
			add[i][j] -= (cntt * val);
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			arr[i][j] += add[i][j];
			add[i][j] = 0;
		}
	}
}

void air() {
	tot -= arr[up - 1][1];
	tot -= arr[down + 1][1];

	//윗 공기

	//왼쪽줄
	for (int i = up - 1; i > 1; i--) arr[i][1] = arr[i - 1][1];
	//윗줄
	for (int i = 1; i < c; i++) arr[1][i] = arr[1][i + 1];
	//오른쪽줄
	for (int i = 2; i <=  up; i++) arr[i -1][c] = arr[i][c];
	//아래줄
	for (int i = c; i > 2; i--) arr[up][i] = arr[up][i - 1];
	arr[up][2] = 0;

	// 아래 공기

	//왼쪽줄
	for (int i = down + 1; i < r; i++) arr[i][1] = arr[i + 1][1];
	//아래줄
	for (int i = 1; i < c; i++) arr[r][i] = arr[r][i + 1];
	//오른쪽줄
	for (int i = r; i > down; i--)arr[i][c] = arr[i - 1][c];
	//윗줄
	for (int i = c; i > 2; i--) arr[down][i] = arr[down][i - 1];
	arr[down][2] = 0;
}

int main() {

	bool flag = 0;
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
			
			if (arr[i][j] == -1) {
				if (!flag) {
					flag = 1;
					up = i;
				}
				else
					down = i;
			}
			else {
				tot += arr[i][j];
				//cout << "tot : " << tot << endl;
			}
				
		}
	}
	
	while (t--) {
		dust();
		air();
	}
	cout << tot << endl;

}