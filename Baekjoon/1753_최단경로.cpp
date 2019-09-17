#include <iostream>
#include <climits>
#include <queue>
using namespace std;

// ���ͽ�Ʈ��

vector<pair<int, int>> info[20001];
int dist[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int v, e,k;
	cin >> v >> e;
	cin >> k; 

	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		
		info[u].push_back({v,w});
	}

	fill(dist, dist + v + 1, INT_MAX);
	priority_queue<pair<int, int>> q;

	q.push({ 0, k });	// ������ �߰�
	dist[k] = 0;		// ������ �ִܰŸ�

	while (!q.empty()) {
		int cost = q.top().first;		// ���� ���
		int pos = q.top().second;		// ���� ��ġ

		q.pop();

		for (int i = 0; i < info[pos].size(); ++i) {		// ���� ����Ǿ��ִ� �� ��ȸ
			int next = info[pos][i].first;
			int ncost = info[pos][i].second;

			if (dist[next] > dist[pos] + ncost) {		// �Ÿ��� �����ؾ� �� ���
				dist[next] = dist[pos] + ncost;
				q.push({-dist[next], next});			// ��� �����ϱ� ���� ť�� ����
			}
		}
	}

	for (int i = 1; i <= v; ++i) {
		if (i == k)
			cout << 0 << "\n";
		else {
			if (dist[i] == INT_MAX)
				cout << "INF" << "\n";
			else
				cout << dist[i] << "\n"
		}
	}

	return 0;
}