#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// ��������

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		int n, m, w;
		cin >> n >> m >> w;

		vector<vector<pair<int, int>>> info(n + 1, vector<pair<int, int>>());

		for (int i = 0; i < m; ++i) {		// �Ϲ� �����
			int u, v, c;
			cin >> u >> v >> c;

			info[u].push_back({ v,c });
			info[v].push_back({ u,c });
		}

		for (int i = 0; i < w; ++i) {		// ��Ȧ �ܹ���
			int u, v, c;
			cin >> u >> v >> c;

			info[v].push_back({ u,-c });	// �ݴ�� ����!
		}

		vector<int> dist(n + 1, INT_MAX);
		dist[1] = 0;
		bool flag = false;

		for (int i = 1; i <= n; ++i) {				// ������ �� ����� �ʿ���� n-1���ٸ� ���� ����ϸ� ��	
			for (int j = 1; j <= n; ++j) {			// ���� 1~N���� ��������
				for (int k = 0; k < info[j].size(); ++k) {		// �������� �� �� �ִ� ��
					if (dist[info[j][k].first] == INT_MAX)		// ������� ���� ���ŵ� ���� �ƴ϶�� ��ŵ
						continue;
					if (dist[j] > dist[info[j][k].first] + info[j][k].second) {		 // ���� ���� �ɶ� 
						dist[j] = dist[info[j][k].first] + info[j][k].second;
						if (i == n) {
							flag = true;
							break;
						}
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}

		if (flag)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}