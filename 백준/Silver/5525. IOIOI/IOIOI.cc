#include <iostream>
#include <string>

using namespace std;
int n, m, cntt;
string s;

int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < s.length(); i++)
	{
		int countt = 0;
		if (s[i] == 'I') {
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				i += 2;
				countt++;
				if (countt == n) {
					cntt++;
					countt--;
				}
			}
			countt = 0;
		}
	}
	cout<<cntt<<endl;
}