#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

// ��������
vector<int> v;

int find(int n) {
	if (v[n] == n)
		return n;
	return v[n] = find(v[n]);
}

void merge(int a, int b) {
	if (a > b)
		swap(a, b);
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	v[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> info(n);

	v.assign(n, 0);

	for (int i = 0; i < n; ++i)		// �ʱ�ȭ
		v[i] = i;

	for (int i = 0; i < m; ++i) {
		int k, l;
		char s;
		cin >> k >> s >> l;

		if (s == '>') 
			info[k].push_back(l);		// ������ ���� �ֵ��� ����
		else
			merge(l, k);				// ���� �Ƿ³��� �����ֱ�
	}

	map<int, set<int>> ninfo;			// ���ο� info
	for (int i = 0; i < n; ++i) {
		set<int> temp;
		ninfo.insert({i,temp});
	}
	vector<int> ndegree(n, 0);			// ���ο� ����

	bool flag = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < info[i].size(); ++j) {
			int lose = find(info[i][j]);			// ������ ���� ��
			int win = find(i);
			if (lose == win) {			// �ڱ� �ڽſ��� ���� = ����Ŭ
				cout << "inconsistent";
				return 0;
			}
			if (ninfo[win].count(lose) == 0)
				++ndegree[lose];
			ninfo[win].insert(lose);
		}
	}

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (ndegree[i] == 0)
			q.push(i);
	}

	int ans = 0;
	while (!q.empty()) {
		int d = q.front();
		q.pop();

		++ans;
		for (auto a : ninfo[d]) {
			--ndegree[a];
			if (ndegree[a] == 0)
				q.push(a);
		}
	}

	if ( ans != n)
		cout << "inconsistent";
	else
		cout << "consistent";

	return 0;
}