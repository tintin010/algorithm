#include <iostream>
#include <string>
using namespace std;
int main() {
	int map[301][301];
	int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> map[i][j];
		}
	}
	while (c > 0) {
		int x1 = 0;
		int y1 = 0;

        int x2 = a - 1;
        int y2 = 0;

        int x3 = a - 1;
        int y3 = b - 1;

        int x4 = 0;
        int y4 = b - 1;
        while ((x2 > x1) && (y1 < y4)) {
            int temp = map[x2][y2];
            for (int i = x2; i > x1; i--) {
                map[i][y2] = map[i - 1][y2];
            }
            for (int i = y1; i < y4; i++) {
                map[x1][i] = map[x1][i + 1];
            }
            for (int i = x4; i < x3; i++) {
                map[i][y4] = map[i+1][y4];
            }
            for (int i = y3; i > y2; i--) {
                map[x2][i] = map[x2][i - 1];
            }
            map[x2][y2 + 1] = temp;
            x1++;
            y1++;
            x2--;
            y2++;
            x3--;
            y3--;
            x4++;
            y4--;
        }
        c--;
	}
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << map[i][j]<<" ";
        }
        cout << endl;
    }
}


	
