#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <climits>
using namespace std;

typedef long long ll;

int getIndex(int n) {			// �迭ũ�� ���ϱ�
	int temp = 1;
	while (temp < n)
		temp = temp << 1;
	return temp * 2;
}

ll init(vector<ll>& a, vector<ll>& tree, int start, int end, int node)
{ // ���׸�Ʈ Ʈ�� ����
	if (start == end)
		return tree[node] = a[start]; // ���� ��忡 ������ ���

	int mid = (start + end) / 2;
	// ��������� �� �κ��� ������ �� �� �ּҰ��� �ڱ� �ڽ����� �Ѵ�.
	return tree[node] = min(init(a, tree, start, mid, node * 2), init(a, tree, mid + 1, end, node * 2 + 1));
}

// left ~ right ������ �ּҰ��� ����, start, end : ����, �� �ε���
ll search_min(vector<ll>& tree, int start, int end, int node, int left, int right)
{
	// ������ ��� ���
	if (left > end || right < start)
		return LLONG_MAX;

	// ���� ���� ���Ե� ��� ���� Ʈ���� �� ����(������)
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return min(search_min(tree, start, mid, node * 2, left, right), search_min(tree, mid + 1, end, node * 2 + 1, left, right));
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("./sample_input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	vector<ll> a(n);
	int tree_size = getIndex(n); // ���׸�Ʈ Ʈ���� ũ��
	vector<ll> tree(tree_size);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	init(a, tree, 0, n - 1, 1); // ���׸�Ʈ Ʈ�� ����

	while (m--)
	{
		int t2, t3;
		cin >> t2 >> t3;
		cout << search_min(tree, 0, n - 1, 1, t2 - 1, t3 - 1) << '\n';
	}

	return 0;
}