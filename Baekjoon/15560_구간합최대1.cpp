#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

/*
A[i]�� U * A[i] + V�� ġȯ
max(A[i] + ... + A[j])�� �ִ밡 �Ǵ� ���� ���� �ִ� ��
*/
const int inf = 1e9;

struct info {
	int lmax;		// ���� ���� �ִ���
	int rmax;		// ������ ���� �ִ���
	int sum;	// �¿� �ִ���
	int tmax;	// �� 2���߿� �ִ�
	info(int lmax = -inf, int rmax = -inf, int sum = 0, int tmax = -inf) :lmax(lmax), rmax(rmax), sum(sum), tmax(tmax) {}
};

int arr[10001];
info tree[1 << 11];

info merge(const info& a, const info& b) {
	return { max(a.lmax, a.sum + b.lmax), max(a.rmax + b.sum, b.rmax), a.sum + b.sum, max({a.tmax,b.tmax,a.rmax + b.lmax}) };
}

info query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return { -inf, -inf, 0, -inf };
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) >> 1;
	info info1 = query(node * 2, start, mid, left, right);
	info info2 = query(node * 2 + 1, mid + 1, end, left, right);
	return merge(info1, info2);
}


void update(int node, int start, int end, int idx, int x) {
	if (idx < start || idx > end)
		return;

	if (start != end) {
		int mid = (start + end) >> 1;
		update(node * 2, start, mid, idx, x);
		update(node * 2 + 1, mid + 1, end, idx, x);
		tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
	}
	else
		tree[node] = { x,x,x,x };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n, q, u, v;
	cin >> n >> q >> u >> v;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		update(1, 1, n, i, u * arr[i] + v);
	}

	while (q--) {
		int c, a, b;
		cin >> c >> a >> b;

		if (c == 0) {		// max(u * (arr[i]+...+arr[j]) + v*(j-i) )  query
			cout << query(1, 1, n, a, b).tmax - v << "\n";
		}
		else {		// arr[a]�� b�� update
			arr[a] = b;
			update(1, 1, n, a, u * b + v);
		}
	}

	return 0;
}