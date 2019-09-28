#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
using namespace std;

// ���ͽ�Ʈ��

vector<pair<int, int>> info[1001];
vector<int> dist;
vector<int> finish;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		info[a].push_back({ b,c });
	}

	priority_queue<pair<int, int>> pq;
	dist.assign(n + 1, 0);		// �� �� �����ߴ��� �����
	finish.assign(n + 1, 0);

	pq.push({ 0,1 });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (dist[pos] == k) 		// �̹� K�� �����ߴٸ� ���� x
			continue;
		if (dist[pos] == k - 1)		// k��° ����
			finish[pos] = cost;
		++dist[pos];		// ������ ��� ����
		for (auto a : info[pos])
			pq.push({ -(cost + a.second),a.first });
	}

	for (int i = 1; i <= n; ++i) {
		if (dist[i] == k)
			cout << finish[i] << "\n";
		else
			cout << "-1\n";
	}

	return 0;
}