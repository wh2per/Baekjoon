#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// ���� ����

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> info(n + 1, vector<pair<int, int>>());

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		info[b].push_back({a,c});		// �ݴ��! (�����Է� �� �� �ִ� ����, �� �� ���)
	}

	vector<int> dist(n + 1, INT_MAX);
	dist[1] = 0;		// ������ �ʱ�ȭ

	for (int i = 1; i < n; ++i) {				// ����� ���� n-1��ŭ ��������
		for (int j = 1; j <= n; ++j) {			// ���� 1~N���� ��������
			for (int k = 0; k < info[j].size(); ++k) {		// �������� �� �� �ִ� ��
				if (dist[info[j][k].first] == INT_MAX)		// ������� ���� ���ŵ� ���� �ƴ϶�� ��ŵ
					continue;
				if (dist[j] > dist[info[j][k].first] + info[j][k].second) {		 // ���� ���� �ɶ� 
					dist[j] = dist[info[j][k].first] + info[j][k].second;
				}
			}
		}
	}
	
	// ���� ����Ŭ�� �ִ� �� �˻�
	bool flag = false;
	for (int j = 1; j <= n; ++j) {			// ���� 1~N���� ��������
		for (int k = 0; k < info[j].size(); ++k) {		// �������� �� �� �ִ� ��
			if (dist[info[j][k].first] == INT_MAX)		// ������� ���� ���ŵ� ���� �ƴ϶�� ��ŵ
				continue;
			if (dist[j] > dist[info[j][k].first] + info[j][k].second) {		 // ���� ���� �ɶ� 
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	if (flag)
		cout << -1 << "\n";
	else {
		for (int i = 2; i <= n; ++i) {
			if (dist[i] == INT_MAX)
				dist[i] = -1;
			cout << dist[i] << "\n";
		}
	}
	return 0;
}