#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<vector<int>> tree;
vector<vector<int>> parent;
vector<int> depth;

void dfs(int now, int dpt) {
	depth[now] = dpt;

	for (auto a : tree[now]) {
		if (depth[a] == -1) {
			dfs(a, dpt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		int n;
		cin >> n;

		int ds = (int)ceil(log2(n)); // MAX_NODE�� log2�� ���� ������ ���ش�.

		tree.assign(n + 1, vector<int>());
		depth.assign(n + 1, -1);
		parent.assign(n + 1, vector<int>(ds, 0));

		for (int i = 0; i < n - 1; ++i) {
			int a, b;
			cin >> a >> b;
			tree[a].push_back(b);
			tree[a].push_back(b);
			parent[b][0] = a;			// 0��°�� �θ� ��ȣ�� ����
		}

		int root;
		for (int i = 1; i <= n; ++i) {
			if (parent[i][0] == 0) {
				root = i;
				break;
			}
		}

		dfs(root, 0);		// depth ���
		
		for (int j = 1; j < ds; ++j) {
			for (int i = 1; i <= n; ++i)
				parent[i][j] = parent[parent[i][j-1]][j-1];			// parent[i][j] = i�� 2^j��° �θ� ����
		}

		int u, v;
		cin >> u >> v;

		if (depth[u] < depth[v])
			swap(u, v);
		int diff = depth[u] - depth[v];		
		for (int j = 0; diff; j++) {		// ���� ���̸�ŭ �ݺ�
			if (diff % 2)					// Ȧ���̸� diff/2 �Ҷ� 0.5�� �������Ƿ� �θ�� �ѹ� �� ������	 
				u = parent[u][j];
			diff /= 2;						// ���̸� ������ ���̰� j�� �������� �θ�� ����
		}

		if (u != v) {		// �θ� ���� ������
			for (int j = ds-1; j >= 0; --j) {
				if (parent[u][j] != 0 && parent[u][j] != parent[v][j]) {		// �θ� �����鼭 ����θ� �ƴϸ�
					u = parent[u][j];			// �θ�� �̵�
					v = parent[v][j];			
				}
			}
			u = parent[u][0];
		}
		cout << u << "\n";
	}

	return 0;
}