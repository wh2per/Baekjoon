#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<vector<int>> parent;
vector<int> depth;
int ds;

void dfs(int now, int dpt) {
	depth[now] = dpt;

	for (auto a : tree[now]) {
		if (depth[a] == -1) {
			parent[a][0] = now;
			dfs(a, dpt + 1);
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	int diff = depth[u] - depth[v];
	for (int j = 0; diff; j++) {		// ���� ���̸�ŭ �ݺ�
		if (diff % 2)
			u = parent[u][j];
		diff /= 2;
	}

	if (u != v) {		// �θ� ���� ������
		for (int j = ds - 1; j >= 0; --j) {
			if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {		// �θ� �����鼭 ����θ� �ƴϸ�
				u = parent[u][j];			// �θ�� �̵�
				v = parent[v][j];
			}
		}
		u = parent[u][0];
	}
	return u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	ds = (int)ceil(log2(n)); // MAX_NODE�� log2�� ���� ������ ���ش�.

	tree.assign(n + 1, vector<int>());
	depth.assign(n + 1, -1);
	parent.assign(n + 1, vector<int>(ds, 0));

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;

		tree[y].push_back(x);
		tree[x].push_back(y);
	}
	dfs(1, 0);

	for (int j = 1; j < ds; ++j) {
		for (int i = 1; i <= n; ++i)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];			// parent[i][j] = i�� 2^j��° �θ� ����
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int r, u, v;
		cin >> r >> u >> v;

		int ans1 = lca(u, v);
		int ans2 = lca(r, v);
		int ans3 = lca(r, u);
		int ans = max(depth[ans1], max(depth[ans2], depth[ans3]));
		if (ans == depth[ans1])
			cout << ans1 << "\n";
		else if (ans == depth[ans2])
			cout << ans2 << "\n";
		else
			cout << ans3 << "\n";
	}

	return 0;
}