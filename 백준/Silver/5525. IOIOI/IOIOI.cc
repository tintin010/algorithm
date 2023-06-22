#include <iostream>
#include <string>

using namespace std;

int n, m;
string s;
int answer = 0;

bool checkIOI(int idx) {
	if (s[idx + 1] == 'O' && s[idx + 2] == 'I') {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> s;

	for (int i = 0; i < m - 2; i++) {
		if (s[i] == 'I') {
			int partLen = 0;
			while (true) {
				if ((i < m - 2) && checkIOI(i)) {
					partLen++;
					i += 2;
					//cout << "partLen : " << partLen << endl;
					//cout << "i : " << i << endl;
				}
				else {
					if (partLen >= n) answer += partLen - n + 1;
					//answer += partLen - n + 1;
					break;
				}
			}
		}
	}

	cout << answer;

	return 0;
}