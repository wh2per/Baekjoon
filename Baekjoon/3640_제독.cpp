#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

int n;

struct edge {
	int next;
	int cost;
	int cap;
	int rev_num;			// ������ ���� ��ġ
	edge(int _next, int _cost, int _cap, int _rev_num) {
		next = _next;
		cost = _cost;
		cap = _cap;
		rev_num = _rev_num;
	}
};

vector<int> prev_num;
vector<int> prev_rev;
vector<vector<edge>> info;

bool spfa(int start, int end) {
	vector<bool> visited(2 * n + 2, false);
	vector<int> dist(2 * n + 2, INT_MAX);
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	visited[start] = true;

	while (q.size()) {
		int pos = q.front();
		visited[pos] = false;
		q.pop();

		for (int i = 0; i < info[pos].size(); i++) {
			int next = info[pos][i].next;
			int cap = info[pos][i].cap;
			int cost = info[pos][i].cost;

			if (cap && dist[next] > dist[pos] + cost) {
				dist[next] = dist[pos] + cost;
				prev_num[next] = pos;
				prev_rev[next] = i;
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
		}
	}

	if (dist[end] != INT_MAX)
		return true;
	else
		return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	while (cin >> n) {
		int m;
		cin >> m;

		prev_num.assign(n * 2 + 2, INT_MAX);		// ���� �θ� ����
		prev_rev.assign(n * 2 + 2, INT_MAX);		// ���� �θ� ����
		info.assign(n * 2 + 2, vector<edge>());	// ������� �����

		for (int i = 1; i <= n; ++i) {
			if (i == 1 || i == n) {			// ���۰� ������ �뷮�� 2�� �ʱ�ȭ
				info[i].push_back(edge(i + n, 0, 2, info[i + n].size()));
				info[i + n].push_back(edge( i, 0, 0, info[i].size() - 1 ));		// ������ ������ �뷮�� 0���� �ʱ�ȭ
			}
			else {
				info[i].push_back(edge( i + n, 0, 1, info[i + n].size() ));
				info[i + n].push_back(edge( i, 0, 0, info[i].size() - 1 ));
			}
		}

		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;

			info[a + n].push_back(edge( b,c,1,info[b].size() ));
			info[b].push_back(edge( a + n,-c,0,info[a + n].size() - 1 ));
		}

		info[0].push_back(edge( 1,0,2,info[1].size() ));
		info[1].push_back(edge( 0,0,2,info[0].size() - 1 ));
		info[n].push_back(edge( 2 * n + 1, 0, 2, info[2*n+1].size() ));
		info[2*n+1].push_back(edge(n, 0, 2, info[n].size()-1));

		int ans = 0;
		int start = 0;
		int end = 2 * n + 1;
		while (spfa(start,end)) {		// ������ �������� �ٲٱ�
			int minf = INT_MAX;			// �ּ� ���� ���ϱ�
			for (int i = end; i != start; i = prev_num[i]) {
				int prev = prev_num[i];
				int rev_edge = prev_rev[i];
				minf = min(minf, info[prev][rev_edge].cap);
			}

			for (int i = end; i != start; i = prev_num[i]) {
				int prev = prev_num[i];
				int rev_edge = prev_rev[i];
				info[prev][rev_edge].cap -= minf;
				info[i][info[prev][rev_edge].rev_num].cap += minf;
				ans += info[prev][rev_edge].cost * minf;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}