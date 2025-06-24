#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, string> dns;
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string url, pw;
        cin >> url >> pw;
        dns[url] = pw;
    }
    for(int i = 0; i < m; i++){
        string url;
        cin >> url;
        cout << dns[url] << '\n';
    }
    return 0;
}