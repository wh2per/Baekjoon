#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// ���ͽ�Ʈ��(40ms) ��������(1008ms)


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int q = 1; q <= tc; ++q) {
		int n, m, t, s, g, h;
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		int temp = 0;
		vector<vector<pair<int, int>>> info(n + 1, vector<pair<int, int>>());
		for (int i = 0; i < m; ++i) {
			int a, b, d;
			cin >> a >> b >> d;

			if ((a == g && b == h) || (b == g && a == h))
				temp = d;

			info[b].push_back({ a,d });
			info[a].push_back({ b,d });
		}

		vector<int> dist1(n + 1, INT_MAX);		// s
		vector<int> dist2(n + 1, INT_MAX);		// g
		vector<int> dist3(n + 1, INT_MAX);		// h

		dist1[s] = 0;		// ������ �ʱ�ȭ
		dist2[g] = 0;		// ������ �ʱ�ȭ
		dist3[h] = 0;		// ������ �ʱ�ȭ
		priority_queue<pair<int, int>> pq1;
		priority_queue<pair<int, int>> pq2;
		priority_queue<pair<int, int>> pq3;
		pq1.push({ 0,s });
		pq2.push({ 0,g });
		pq3.push({ 0,h });
		while (!pq1.empty()) {
			int cost = pq1.top().first;
			int pos = pq1.top().second;
			pq1.pop();

			for (int i = 0; i < info[pos].size(); ++i) {
				int next = info[pos][i].first;
				int ncost = info[pos][i].second;

				if (dist1[next] > dist1[pos] + ncost) {		// �Ÿ��� �����ؾ� �� ���
					dist1[next] = dist1[pos] + ncost;
					pq1.push({ -dist1[next], next });			// ��� �����ϱ� ���� ť�� ����
				}
			}
		}

		while (!pq2.empty()) {
			int cost = pq2.top().first;
			int pos = pq2.top().second;
			pq2.pop();

			for (int i = 0; i < info[pos].size(); ++i) {
				int next = info[pos][i].first;
				int ncost = info[pos][i].second;

				if (dist2[next] > dist2[pos] + ncost) {		// �Ÿ��� �����ؾ� �� ���
					dist2[next] = dist2[pos] + ncost;
					pq2.push({ -dist2[next], next });			// ��� �����ϱ� ���� ť�� ����
				}
			}
		}

		while (!pq3.empty()) {
			int cost = pq3.top().first;
			int pos = pq3.top().second;
			pq3.pop();

			for (int i = 0; i < info[pos].size(); ++i) {
				int next = info[pos][i].first;
				int ncost = info[pos][i].second;

				if (dist3[next] > dist3[pos] + ncost) {		// �Ÿ��� �����ؾ� �� ���
					dist3[next] = dist3[pos] + ncost;
					pq3.push({ -dist1[next], next });			// ��� �����ϱ� ���� ť�� ����
				}
			}
		}

		vector<int> ans;
		for (int i = 0; i < t; ++i) {
			int x;
			cin >> x;

			if ((dist1[g] + temp + dist3[x] == dist1[x]) || (dist1[h] + temp + dist2[x] == dist1[x]))
				ans.push_back(x);
		}

		sort(ans.begin(), ans.end());
		for (auto a : ans)
			cout << a << " ";
		cout << "\n";
	}
	return 0;
}
