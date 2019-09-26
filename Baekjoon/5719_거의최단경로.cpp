#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
using namespace std;

// ���ͽ�Ʈ��

vector<pair<int, int>> info[500];
vector<int> dist;
vector<vector<int>> path[500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	while (1) {
		int n, m, s, d;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		cin >> s >> d;
		
		for (int i = 0; i < 500; ++i) {		// info,path �ʱ�ȭ
			info[i].clear();
			path[i].clear();
		}
		dist.assign(n,INT_MAX);

		for (int i = 0; i < m; ++i) {
			int u, v, p;
			cin >> u >> v >> p;
			info[u].push_back({v,p});
		}

		priority_queue<pair<int, int>> q;
		
		dist[s] = 0;
		q.push({ 0,s });
		vector<int> start;
		start.push_back(s);
		path[s].push_back(start);

		while (!q.empty()) {
			int cost = -q.top().first;
			int pos = q.top().second;
			q.pop();

			if (cost > dist[d])		// ��� �ʰ����� ��� ��ŵ
				continue;

			for (auto a : info[pos]) {
				int next = a.first;
				int ncost = a.second;

				if (dist[next] > dist[pos] + ncost) {		// �Ÿ��� �����ؾ� �� ���
					dist[next] = dist[pos] + ncost;
					q.push({-dist[next],next});

					path[next].clear();
					for (auto b : path[pos]) {			// ����� ����
						b.push_back(next);
						path[next].push_back(b);
					}
				}
				else if (dist[next] == dist[pos] + ncost) {		// path�� �߰�����
					for (auto b : path[pos]) {			// ����� ����
						b.push_back(next);
						path[next].push_back(b);
					}
				}
			}
		}

		for (auto a : path[d]) {		// �����ؾ��� path��
			for (int i = 0; i < a.size()-1; ++i) {
				for (int j = 0; j < info[a[i]].size(); ++j) {
					if (info[a[i]][j].first == a[i + 1])
						info[a[i]][j].second = -1;			// �ڽ�Ʈ�� -1�� �ٲ������
				}
			}
		}

		dist.assign(n, INT_MAX);
		priority_queue<pair<int, int>> nq;
		
		dist[s] = 0;
		nq.push({ 0,s });
		while (!nq.empty()) {
			int cost = -nq.top().first;
			int pos = nq.top().second;
			nq.pop();

			if (pos == d)
				break;

			for (int i = 0; i < info[pos].size(); ++i) {
				if (info[pos][i].second == -1)
					continue;
				int ncost = info[pos][i].second;
				int next = info[pos][i].first;

				if (dist[next] > dist[pos] + ncost) {
					dist[next] = dist[pos] + ncost;
					nq.push({-dist[next], next});
				}
			}
		}

		if (dist[d] == INT_MAX)
			cout << "-1\n";
		else
			cout << dist[d] << "\n";
	}

	return 0;
}