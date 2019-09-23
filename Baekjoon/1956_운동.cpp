#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// �÷��̵� �ͼ�

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	vector<vector<int>> info(v + 1, vector<int>(v + 1, INT_MAX));

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		info[a][b] = c;
	}

	for (int i = 1; i <= v; ++i)
		info[i][i] = 0;

	for (int i = 1; i <= v; ++i) {		// ����
		for (int j = 1; j <= v; ++j) {	// ������
			if (info[j][i] == INT_MAX)
				continue;
			for (int k = 1; k <= v; ++k) { 	// ������
				if (info[i][k] == INT_MAX)
					continue;
				if (info[j][k] > info[j][i] + info[i][k])		// ����-���� ���� ���ų� �����ϴ� �ͺ��� Ŭ��
					info[j][k] = info[j][i] + info[i][k];
			}
		}
	}
	int ans = INT_MAX;

	for (int i = 1; i <= v; ++i) {
		for (int j = 1; j <= v; ++j) {
			if (i==j || info[i][j] == INT_MAX || info[j][i] == INT_MAX)
				continue;
			ans = min(ans, info[i][j] + info[j][i]);
		}
	}
	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans;

	return 0;
}