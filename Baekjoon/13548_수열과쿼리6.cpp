#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
int mcnt;
int v[1000001];
int cnt[1000001];
int ans[1000001];
int table[1000001];	 // table[3] = 5�̸�, ���������� 3�� �����ϴ� ���� 5������ �ִٴ� ��

void sub(int num) {
	if (mcnt == cnt[num] && table[mcnt] == 1)	// mcnt�� num�� �󵵼� �̸鼭 �� �󵵼��� ���� ���� 1������ ��� 
		--mcnt;
	--table[cnt[num]];		// num�� �󵵼��� ���� ���ڸ� �ϳ� ����
	--cnt[num];				// num�� �󵵼� ����
	++table[cnt[num]];		// num�� �󵵼��� ���� ���� �ϳ� ����
}

void add(int num) {
	--table[cnt[num]];		// num�� �󵵼��� ���� ���ڸ� �ϳ� ���� (��� ���� ���� �������̱� ����)
	++cnt[num];				// num�� �󵵼� ����
	++table[cnt[num]];		// num�� �󵵼��� ���� ���ڸ� �ϳ� ���� (�갡 ���� �������̱� ����)

	if (mcnt < cnt[num])	// ������ �Ѱ��� �˻��ϹǷ� ������ 1������
		++mcnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int start, end;
		cin >> start >> end;
		query.emplace_back(i, start - 1, end - 1);
	}
	sqrtN = sqrt(n);
	sort(query.begin(), query.end(), cmp);			// ���� ����

	int s = 0;
	int e = -1;
	mcnt = 0;

	for (auto a : query) {
		int ns = a.s;
		int ne = a.e;

		for (int i = s - 1; i >= ns; --i)	// s�� ns���� �����ʿ� �ִ� ��� : ���� ���� �ʿ䰡 �ִ�
			add(v[i]);
		for (int i = e + 1; i <= ne; ++i)	// e�� ne���� ���ʿ� �ִ� ��� : ���� ���� �ʿ䰡 �ִ�
			add(v[i]);
		for (int i = e; i > ne; --i)		// e�� ne���� �����ʿ� �ִ� ��� : ���� ������ �ʿ䰡 �ִ�
			sub(v[i]);
		for (int i = s; i < ns; ++i)		// s�� ns���� ���ʿ� �ִ� ��� : ���� ������ �ʿ䰡 �ִ�
			sub(v[i]);

		s = ns;
		e = ne;

		ans[a.idx] = mcnt;
	}

	for (int i = 0; i < q; ++i)
		cout << ans[i] << "\n";

	return 0;
}