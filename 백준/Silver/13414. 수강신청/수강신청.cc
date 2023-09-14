//13414 수강신청

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

int main() {
	vector<pair<int, string>>v;
	map<string, int>m;
	int k, l;
	cin >> k >> l;
	for (int i = 0; i < l; i++) {
		string str;
		cin >> str;
		m[str] = i;
	}
	for (auto a : m) {
		
		v.push_back({a.second ,a.first });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < min(k, (int)v.size()); i++) {
		cout << v[i].second << '\n';
	}
}