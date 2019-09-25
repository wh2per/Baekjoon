#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<vector<pair<int,int>>> tree;
vector<vector<int>> parent;
vector<vector<long long>> cost;
vector<int> depth;

void dfs(int now, int dpt) {
	depth[now] = dpt;

	for (auto a : tree[now]) {
		if (depth[a.first] == -1) {
			parent[a.first][0] = now;			// 0��°�� �θ� ����
			cost[a.first][0] = a.second;
			dfs(a.first, dpt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int ds = (int)ceil(log2(n)); // MAX_NODE�� log2�� ���� ������ ���ش�.
	tree.assign(n + 1, vector<pair<int, int>>());
	parent.assign(n + 1, vector<int>(ds, 0));
	cost.assign(n + 1, vector<long long>(ds, 0));
	depth.assign(n + 1, -1);

	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		tree[u].push_back({ v,w });
		tree[v].push_back({ u,w });
	}
	dfs(1, 0);			// root ��带 1�� ����

	for (int j = 1; j < ds; ++j) {
		for (int i = 1; i <= n; ++i) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];		// parent[i][j] = i�� 2^j��° �θ��ȣ�� ����
			if(cost[parent[i][j - 1]][j - 1] !=0)
				cost[i][j] = cost[i][j-1] + cost[parent[i][j-1]][j-1];				// cost[i][j] = i�� 2^j��° �θ� ���� ����� ����
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {			// ��� ��� ���
			long long ans = 0;
			cin >> b >> c;

			if (depth[b] < depth[c])
				swap(b, c);
			int diff = depth[b] - depth[c];
			for (int j = 0; diff; j++) {		// ���� ���̸�ŭ �ݺ�
				if (diff % 2) {					// Ȧ���̸� diff/2 �Ҷ� 0.5�� �������Ƿ� �θ�� �ѹ� �� ������	 
					ans += cost[b][j];			// ������� ���µ� �ɷȴ� ��� ���ϱ�
					b = parent[b][j];
				}
				diff /= 2;						// ���̸� ������ ���̰� j�� �������� �θ�� ����
			}

			if (b != c) {		// �θ� ���� ������
				for (int j = ds - 1; j >= 0; --j) {
					if (parent[b][j] != 0 && parent[b][j] != parent[c][j]) {		// �θ� �����鼭 ����θ� �ƴϸ�
						ans += cost[b][j];
						ans += cost[c][j];
						b = parent[b][j];			// �θ�� �̵�
						c = parent[c][j];
					}
				}
				ans += cost[b][0];
				ans += cost[c][0];
			}
			cout << ans << "\n";
		}
		else {					// d��° ���� ���
			cin >> b >> c >> d;
			int u = b, v = c;
			int ans = 0;

			if (depth[b] < depth[c])
				swap(b, c);
			int diff = depth[b] - depth[c];
			for (int j = 0; diff; j++) {		// ���� ���̸�ŭ �ݺ�
				if (diff % 2) 					// Ȧ���̸� diff/2 �Ҷ� 0.5�� �������Ƿ� �θ�� �ѹ� �� ������	 
					b = parent[b][j];
				diff /= 2;						// ���̸� ������ ���̰� j�� �������� �θ�� ����
			}

			if (b != c) {		// �θ� ���� ������
				for (int j = ds - 1; j >= 0; --j) {
					if (parent[b][j] != 0 && parent[b][j] != parent[c][j]) {		// �θ� �����鼭 ����θ� �ƴϸ�
						b = parent[b][j];			// �θ�� �̵�
						c = parent[c][j];
					}
				}
				b = parent[b][0];
			}

			int db = depth[u] - depth[b];		// ������� lca�� depth��
			if (db >= d-1) {						// d��ŭ u���� �ö󰡱�
				--d;
				for (int j = 0; d; j++) {
					if (d % 2)
						u = parent[u][j];
					d /= 2;
				}
				ans = u;
			}
			else {
				int dc = d - db - 1; 		// ���� ���� dc��ŭ lca���� ���������� = depth[v]-depth[b]-dc ��ŭ v���� �ö󰡱� 
				dc = depth[v] - depth[b] - dc;
				for (int j = 0; dc; j++) {
					if (dc % 2)
						v = parent[v][j];
					dc /= 2;
				}
				ans = v;
			}
			cout << ans << "\n";
		}
	}

	return 0;
}