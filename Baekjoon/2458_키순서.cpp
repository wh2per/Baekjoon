#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ans = 0;
	cin >> n >> m;

	vector<vector<int>> d(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;		// ũ��
		d[b][a] = -1;		// �۴�
	}

	for (int i = 1; i <= n; ++i) {
		for (int from = 1; from <= n; ++from) {
			if (d[from][i] == 0)
				continue;
			for (int to = 1; to <= n; ++to) {			// ��ü �ֵ��� ���鼭
				if (d[from][i] == d[i][to])				// ���� i�� ���谡 i�� to�� ���谡 ���ٸ�
					d[from][to] = d[from][i];			// ���� to�� �׵��� ����� ����.
			}											// ��, ���� a���� ���ٸ� a���� �̱������׵� �� ����.
		}
	}

	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] != 0 && (i != j))
				++sum;
		}
		if (sum == n - 1)
			++ans;
	}
	cout << ans;
	return 0;
}