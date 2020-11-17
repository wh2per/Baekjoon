#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
	// ��������� �� �κ��� ������ �� ���� �ڱ� �ڽ����� �Ѵ�.
	return tree[node] = init(a, tree, start, mid, node * 2) + init(a, tree, mid + 1, end, node * 2 + 1);
}

// left ~ right ������ �������� ����, start, end : ����, �� �ε���
ll sum(vector<ll>& tree, int start, int end, int node, int left, int right)
{
	// ������ ��� ���
	if (left > end || right < start)
		return 0;

	// ���� ���� ���Ե� ��� ���� Ʈ���� �� ����(������)
	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(tree, start, mid, node * 2, left, right) + sum(tree, mid + 1, end, node * 2 + 1, left, right);
}

// index : ������ ����� �ε���, dif : ����� ���̰�
void update(vector<ll>& tree, int start, int end, int node, int index, ll dif)
{
	// ������ ��� ���
	if (index < start || index > end)
		return;
	tree[node] += dif; // ������ ��尡 ���Ե� ������ ���� ����

	if (start == end)
		return; // ������ ��带 ã�� ���

	int mid = (start + end) / 2;
	update(tree, start, mid, node * 2, index, dif);
	update(tree, mid + 1, end, node * 2 + 1, index, dif);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("./sample_input.txt", "r", stdin);

	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> a(n);
	int tree_size = getIndex(n); // ���׸�Ʈ Ʈ���� ũ��
	vector<ll> tree(tree_size);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	init(a, tree, 0, n - 1, 1); // ���׸�Ʈ Ʈ�� ����

	k += m; // m + k�� �ݺ�
	while (k--)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if (t1 == 1)
		{
			t2--; // �ε����� ����
			ll dif = (ll)(t3 - a[t2]); // ���̰� ����
			a[t2] = t3; // a[t2] �� ����
			update(tree, 0, n - 1, 1, t2, dif);
		}
		else if (t1 == 2)
		{
			cout << sum(tree, 0, n - 1, 1, t2 - 1, t3 - 1) << '\n';
		}
	}

	return 0;
}