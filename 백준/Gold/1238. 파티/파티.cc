//1238 파티 -RE-

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 1010
#define INF 987654321

using namespace std;

int n, m, x, anss;
int dis[MAX], res[MAX];
vector<pair<int, int>> v[MAX];

void dijk(int k) {
    priority_queue<pair<int, int>> pq;
    dis[k] = 0;
    pq.push(make_pair(0, k));
    while (pq.empty() == 0)
    {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[now].size(); i++)
        {
            int n = v[now][i].first;
            int nc = v[now][i].second;

            if (dis[n] > cost + nc)
            {
                dis[n] = cost + nc;
                pq.push(make_pair(-dis[n], n));
            }
        }
    }
}

int main() {
	cin >> n >> m >> x;
	for (int i = 0;i < m;i++) {
		int st, ed, cost;
		cin >> st >> ed >> cost;
		v[st].push_back({ ed,cost });
	}

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) dis[j] = INF;
        dijk(i);
        res[i] = dis[x];
    }
    for (int j = 1; j <= n; j++) dis[j] = INF;
    dijk(x);
    for (int i = 1; i <= n; i++) res[i] = res[i] + dis[i];
    sort(res + 1, res + n + 1);
    anss = res[n];
    cout << anss;
}