#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> discoverd;
vector<bool> ans;
int number;
vector<vector<int>> info;
int sum;

int dfs(int here, bool isroot) {
	discoverd[here] = ++number;		// Ž�� ���� ����
	int curr = discoverd[here];

	int child = 0;
	for (int i = 0; i < info[here].size(); ++i) {
		int next = info[here][i];

		if (discoverd[next]) 		// �̹� Ž���� �����϶�
			curr = min(curr, discoverd[next]);
		else {
			++child;
			int prev = dfs(next, false);		// Ž������ ���� �����̸� dfs����
			if (!isroot && prev >= discoverd[here])
				ans[here] = true;

			curr = min(curr, prev);
		}
	}

	if (isroot && child>=2) 
		ans[here] = true;

	return curr;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	info.assign(v + 1, vector<int>());
	discoverd.assign(v + 1, 0);
	ans.assign(v + 1, false);

	for (int i = 0; i < e; ++i) {
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
		info[b].push_back(a);
	}

	for (int i = 1; i <= v; ++i) {
		if (!discoverd[i])
			dfs(i, true);
	}

	for (int i = 1; i <= v; ++i) {
		if (ans[i])
			++sum;
	}

	cout << sum << "\n";
	for (int i = 1; i <= v; ++i) {
		if (ans[i])
			cout << i << " ";
	}
	return 0;
}