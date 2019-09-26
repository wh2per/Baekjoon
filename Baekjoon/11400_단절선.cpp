#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> discoverd;
vector<pair<int, int>> ans;
int number;
vector<vector<int>> info;

int dfs(int here, int prev) {
	discoverd[here] = ++number;		// Ž�� ���� ����
	int curr = discoverd[here];

	for (int i = 0; i < info[here].size(); ++i) {
		int next = info[here][i];

		if (next == prev)		// �θ� �����
			continue;

		if (discoverd[next]) 		// �̹� Ž���� �����϶�
			curr = min(curr, discoverd[next]);
		else {
			int where = dfs(next, here);		// here�� �ڽ� ��尡 �� �� �ִ� ����� ���� ó�� �湮�� ���
			if (where > discoverd[here])
				ans.push_back({min(here,next), max(here,next)});
			curr = min(curr, where);
		}
	}
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

	for (int i = 0; i < e; ++i) {
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
		info[b].push_back(a);
	}

	for (int i = 1; i <= v; ++i) {
		if (!discoverd[i])
			dfs(i, 0);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto a : ans)
		cout << a.first << " " << a.second << "\n";

	return 0;
}