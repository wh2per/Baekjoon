#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// �ּҽ���Ʈ��(MST) -> ũ�罺Į or ����

int v[1001];

struct info {
	int x;
	int y;
	int cost;
};

bool cmp_cost(info c1, info c2) {
	if (c1.cost < c2.cost)
		return true;
	else
		return false;
}

int find(int n)
{
	if (v[n] == n)
		return n;
	v[n] = find(v[n]);
	return v[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)		// ���� �ڽ��� ���� �ʱ�ȭ
		v[i] = i;

	vector<info> ci;
	for (int i = 0; i < m; ++i) {
		struct info nc;
		cin >> nc.x >> nc.y >> nc.cost;
		ci.push_back(nc);
	}
	sort(ci.begin(), ci.end(), cmp_cost);	// ����� ���� ������ ����	

	int ans = 0;
	int p1, p2;
	for (int i = 0; i<ci.size(); i++) {
		p1 = find(ci[i].x);
		p2 = find(ci[i].y);

		if (p1 == p2)		// ����Ŭ�� �����ǹǷ� ��ŵ
			continue;

		v[p1] = p2;			// ä��
		ans += ci[i].cost;	
	}
	cout << ans;
	return 0;
}