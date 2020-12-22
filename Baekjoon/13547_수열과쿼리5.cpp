#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

struct Query {
	int idx, s, e;
	Query(int idx, int s, int e) : idx(idx), s(s), e(e) {}
};

int sqrtN;

bool cmp(Query& x1, Query& x2) {
	if (x1.e / sqrtN == x2.e / sqrtN)
		return x1.s < x2.s;
	return x1.e / sqrtN < x2.e / sqrtN;
}
// ������ ������ �κ��� ��� ������ ���ϴ��� Ȯ���ϴ�
// ������ �ε����� �� �������� ���ϴ� ������ ���� ó���Ѵ�
// ���� ������ �ε����� ���ٸ� ������ ���������� �������� ���� ó���Ѵ�
vector<Query> query;

int n, q;
int now;
int mp[1000001];
int cnt[1000001];
int ans[1000001];

void sub(int num) {
	--cnt[num];
	if (cnt[num] == 0)
		--now;
}

void add(int num) {
	++cnt[num];
	if (cnt[num] == 1)
		++now;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> mp[i];

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int start, end;
		cin >> start >> end;
		query.emplace_back(i, start - 1, end - 1);
	}
	sqrtN = sqrt(n);
	sort(query.begin(), query.end(), cmp);			// ���� ����

	int s = 0;
	int e = 0;
	add(mp[0]);

	for (auto a : query) {
		int ns = a.s;
		int ne = a.e;

		for (int i = s; i < ns; ++i)		// s�� ns���� ���ʿ� �ִ� ��� : ���� ������ �ʿ䰡 �ִ�
			sub(mp[i]);
		for (int i = s - 1; i >= ns; --i)	// s�� ns���� �����ʿ� �ִ� ��� : ���� ���� �ʿ䰡 �ִ�
			add(mp[i]);
		for (int i = e + 1; i <= ne; ++i)	// e�� ne���� ���ʿ� �ִ� ��� : ���� ���� �ʿ䰡 �ִ�
			add(mp[i]);
		for (int i = e; i > ne; --i)		// e�� ne���� �����ʿ� �ִ� ��� : ���� ������ �ʿ䰡 �ִ�
			sub(mp[i]);

		s = ns;
		e = ne;

		ans[a.idx] = now;
	}

	for (int i = 0; i < q; ++i)
		cout << ans[i] << "\n";

	return 0;
}