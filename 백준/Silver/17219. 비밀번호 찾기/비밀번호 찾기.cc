//17219 비밀번호 찾기

#include <iostream>
#include <map>
#include <string>

using namespace std;
int n, m;
map<string, string>mp;


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string  site, pw;
		cin >> site >> pw;
		mp[site] = pw;
	}
	for (int i = 0; i < m; i++) {
		string  site;
		cin >> site;
		cout << mp[site] << endl;
	}
}