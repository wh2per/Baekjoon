#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;

	int ds = (int)ceil(log2(500000)); // MAX_NODE�� log2�� ���� �ø��� ���ش�.
	vector<vector<int>> parent(m + 1, vector<int>(ds, 0));

	for (int i = 1; i <= m; ++i)		// i�� �θ� ����
		cin >> parent[i][0];

	for (int j = 1; j < ds; ++j) {
		for (int i = 1; i <= m; ++i)
			parent[i][j] = parent[parent[i][j-1]][j-1];		// parent[i][j] = i�� 2^j��° �θ��ȣ�� ����
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, x;
		cin >> n >> x;

		for (int j = 0; n; ++j) {
			if (n % 2)
				x = parent[x][j];
			n /= 2;
		}

		cout << x<<'\n';
	}

	return 0;
}