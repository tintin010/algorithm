#include<iostream>
#include<queue>
#include<vector>

#define endl "\n"
#define MAX 20010
#define INF 987654321
using namespace std;
int v, e, st;
int dis[MAX];
vector<pair<int, int>> ver[MAX];

void input() {
    cin >> v >> e >> st;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ver[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= v; i++)dis[i] = INF;
}

void sol() {
    priority_queue<pair<int, int>>p;
    p.push(make_pair(0, st));
    dis[st] = 0;

    while (p.empty() == 0) {
        int cost = -p.top().first;
        int cur = p.top().second;
        p.pop();

        for (int i = 0; i < ver[cur].size(); i++) {
            int next = ver[cur][i].first;
            int ncost = ver[cur][i].second;

            if (dis[next] > cost + ncost) {
                dis[next] = cost + ncost;
                p.push(make_pair(-dis[next], next));
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (dis[i] == INF)cout << "INF" << endl;
        else cout << dis[i] << endl;
    }
}

int main(void)

{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    sol();

    return 0;

}